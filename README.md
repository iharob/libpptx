# libpptx
Biblioteca para la lectura de archivos .pptx de MS PowerPoint

This is an implementation of the OpenXML format for PowerPoint documents, it was mainly used to generate HTML documents from .pptx documents, it was a real challenge given that it's near to impossible to do this with high fidelity with css's limitations.

To use it correctly the programmer needs to understand how OpenXML format works and be familiar with the parts of a power point document. To use this, you need

1. [libxml2](https://www.google.co.ve/url?sa=t&rct=j&q=&esrc=s&source=web&cd=1&cad=rja&uact=8&ved=0ahUKEwi16oOL6rnTAhUJZCYKHYebD04QFggjMAA&url=http%3A%2F%2Fxmlsoft.org%2F&usg=AFQjCNH6UicY70qLDVGTEZCAGPdZzJSgFw&sig2=-IHVCxhDhz5I18ipv94Jhw) XML parsing library.
2. Some zip archive manipulation library, like [libarchive](http://www.libarchive.org/).
3. Of course, a c compiler with support for the c99 standard or newer.

The basic mechanism is to read the file representing a given part in the document with the zip archive manipulator and then pass the text to the libxml2 XML parser, the root node is then passed to libpptx's corresponding *new* function and then access to all the members that make up the targeted Complex Type is provided by means of accessor functions.

The following is an example using the [czipio](https://github.com/iharob/czipio) library,

```c
#include <pptx.h>
#include <czipio-entry.h>
#include <czipio.h>

#define PATH "/media/files/projects/sources/ovas/src/mdm01_cic01_s001/mdm01_cic01_s001.pptx"

xmlDoc *
xml_document_from_zip_entry(const czipio_entry *const entry)
{
    const char *content;
    size_t length;
    // Cast to `const char *' because this function retunrs
    // `const uint8_t *` but it's utf-8, so it's safe to cast
    // and pass the text to `xmlParseMemory()'
    content = (const char *) czipio_entry_content(entry);
    length = czipio_entry_size(entry);
    // Return the parse document
    return xmlParseMemory(content, length);
}

static void
parse_presentation(pptx_ct_p_presentation *pptx)
{
    pptx_ct_p_slide_id_list *id_lst;
    pptx_ct_p_slide_id_list_entry **sld_id_lst;
    id_lst = pptx_ct_p_presentation_get_sld_id_lst(pptx);
    if (id_lst == NULL)
        return; // There are no slides?
    sld_id_lst = pptx_ct_p_slide_id_list_get_sld_id(id_lst);
    if (sld_id_lst == NULL)
        return; // The list is empty?
    for (int i = 0; sld_id_lst[i] != NULL; ++i) {
        pptx_string r_id;
        r_id = pptx_ct_p_slide_id_list_entry_get_r_id(sld_id_lst[i]);
        if (r_id == NULL)
            continue; // Unlikely, but not impossible
        fprintf(stdout, "slide found with id: `%s'\n", r_id);
        // TODO: Use the id to find the relation from `presentation.xml.rels'
        //       and read each slide, which in turn has shapes and other parts.
        //
        //       To build a complete reader/parser the developer needs to read
        //       the specification, everything is then accessible here.
    }
}

static void
handle_xml_document(xmlDoc *document)
{
    pptx_ct_p_presentation *pptx;
    xmlNode *root;
    root = xmlDocGetRootElement(document);
    if (root == NULL)
        return; // Silently ignore this (it's really unlikely)
    pptx = pptx_ct_p_presentation_new(root);
    if (pptx != NULL) {
        parse_presentation(pptx);
        pptx_ct_p_presentation_free(pptx);
    }
}

int
main(int argc, char **argv)
{
    const czipio_entry *entry;
    czipio_file *file;
    file = czipio_open(PATH);
    if (file == NULL)
        return -1;
    entry = czipio_find(file, "ppt/presentation.xml");
    if (entry == NULL)
        goto error;
    xmlDoc *document;
    document = xml_document_from_zip_entry(entry);
    if (document != NULL) {
        handle_xml_document(document);
        xmlFreeDoc(document);
     }
    czipio_close(file);
    return 0;
error:
    czipio_close(file);
    return -1;
}
```
    
will create a new presentation object, where `pptx_ct_p_presentation` is the c representation of the `CT_Presentation` complex type which belongs to the *p* namespace, as defined by the specs.

Only a single header is required *pptx.h*, and it cannot be included in another header file. If you think this is a bad decision and you have a good explanation of why, I can reconsider and fix it.

A pkg-config file is provided too to enable developers easy usage of this library.

Also, in the future it might be interesting to add write capability because for the moment it is only possible to read documents.

# Disclaimer

This code was **generated** from the XSD schema defintions, if you feel that I did violate the DYR principle it is because I did, the code is repeated because it's generated from a template.

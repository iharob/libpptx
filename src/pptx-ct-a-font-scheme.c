#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-font-scheme.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-font-collection.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_font_scheme_s {
    pptx_ct_a_font_collection *major_font;
    pptx_ct_a_font_collection *minor_font;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string name;
    int32_t index;
} pptx_ct_a_font_scheme;

pptx_ct_a_font_scheme *
pptx_ct_a_font_scheme_new(xmlNode *node)
{
    pptx_ct_a_font_scheme *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:majorFont");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->major_font = NULL;
        } else {
            obj->major_font = pptx_ct_a_font_collection_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->major_font = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:minorFont");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->minor_font = NULL;
        } else {
            obj->minor_font = pptx_ct_a_font_collection_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->minor_font = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_office_art_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_font_collection *
pptx_ct_a_font_scheme_get_major_font(const pptx_ct_a_font_scheme *const obj)
{
    return obj->major_font;
}

pptx_ct_a_font_collection *
pptx_ct_a_font_scheme_get_minor_font(const pptx_ct_a_font_scheme *const obj)
{
    return obj->minor_font;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_font_scheme_get_ext_lst(const pptx_ct_a_font_scheme *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_font_scheme_get_name(const pptx_ct_a_font_scheme *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_a_font_scheme_get_index(pptx_ct_a_font_scheme *obj)
{
    return obj->index;
}

void
pptx_ct_a_font_scheme_free(pptx_ct_a_font_scheme *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_font_collection_free(obj->major_font);
    pptx_ct_a_font_collection_free(obj->minor_font);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    free(obj);
}
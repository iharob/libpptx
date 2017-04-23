#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-embedded-wavaudio-file.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_embedded_wavaudio_file_s {
    pptx_string embed;
    pptx_string name;
    int32_t index;
} pptx_ct_a_embedded_wavaudio_file;

pptx_ct_a_embedded_wavaudio_file *
pptx_ct_a_embedded_wavaudio_file_new(xmlNode *node)
{
    pptx_ct_a_embedded_wavaudio_file *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->embed = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:embed");
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_embedded_wavaudio_file_get_embed(const pptx_ct_a_embedded_wavaudio_file *const obj)
{
    return obj->embed;
}

pptx_string 
pptx_ct_a_embedded_wavaudio_file_get_name(const pptx_ct_a_embedded_wavaudio_file *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_a_embedded_wavaudio_file_get_index(pptx_ct_a_embedded_wavaudio_file *obj)
{
    return obj->index;
}

void
pptx_ct_a_embedded_wavaudio_file_free(pptx_ct_a_embedded_wavaudio_file *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->embed);
    xmlFree(obj->name);
    free(obj);
}
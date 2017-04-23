#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-external-data.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_external_data_s {
    pptx_bool auto_update;
    pptx_string r_id;
    int32_t index;
} pptx_ct_a_external_data;

pptx_ct_a_external_data *
pptx_ct_a_external_data_new(xmlNode *node)
{
    pptx_ct_a_external_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->auto_update = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:autoUpdate");
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_bool 
pptx_ct_a_external_data_get_auto_update(const pptx_ct_a_external_data *const obj)
{
    return obj->auto_update;
}

pptx_string 
pptx_ct_a_external_data_get_r_id(const pptx_ct_a_external_data *const obj)
{
    return obj->r_id;
}

int32_t
pptx_ct_a_external_data_get_index(pptx_ct_a_external_data *obj)
{
    return obj->index;
}

void
pptx_ct_a_external_data_free(pptx_ct_a_external_data *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->r_id);
    free(obj);
}
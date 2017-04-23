#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tags-data.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_tags_data_s {
    pptx_string r_id;
    int32_t index;
} pptx_ct_p_tags_data;

pptx_ct_p_tags_data *
pptx_ct_p_tags_data_new(xmlNode *node)
{
    pptx_ct_p_tags_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_tags_data_get_r_id(const pptx_ct_p_tags_data *const obj)
{
    return obj->r_id;
}

int32_t
pptx_ct_p_tags_data_get_index(pptx_ct_p_tags_data *obj)
{
    return obj->index;
}

void
pptx_ct_p_tags_data_free(pptx_ct_p_tags_data *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->r_id);
    free(obj);
}
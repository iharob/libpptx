#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-smart-tags.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_smart_tags_s {
    pptx_string r_id;
    int32_t index;
} pptx_ct_p_smart_tags;

pptx_ct_p_smart_tags *
pptx_ct_p_smart_tags_new(xmlNode *node)
{
    pptx_ct_p_smart_tags *obj;
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
pptx_ct_p_smart_tags_get_r_id(const pptx_ct_p_smart_tags *const obj)
{
    return obj->r_id;
}

int32_t
pptx_ct_p_smart_tags_get_index(pptx_ct_p_smart_tags *obj)
{
    return obj->index;
}

void
pptx_ct_p_smart_tags_free(pptx_ct_p_smart_tags *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->r_id);
    free(obj);
}
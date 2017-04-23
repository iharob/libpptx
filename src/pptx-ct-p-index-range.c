#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-index-range.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_index_range_s {
    pptx_uint st;
    pptx_uint end;
    int32_t index;
} pptx_ct_p_index_range;

pptx_ct_p_index_range *
pptx_ct_p_index_range_new(xmlNode *node)
{
    pptx_ct_p_index_range *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->st = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "st");
    obj->end = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "end");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_p_index_range_get_st(const pptx_ct_p_index_range *const obj)
{
    return obj->st;
}

pptx_uint 
pptx_ct_p_index_range_get_end(const pptx_ct_p_index_range *const obj)
{
    return obj->end;
}

int32_t
pptx_ct_p_index_range_get_index(pptx_ct_p_index_range *obj)
{
    return obj->index;
}

void
pptx_ct_p_index_range_free(pptx_ct_p_index_range *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
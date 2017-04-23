#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-adj.h>
/* Imported internal stuff */

typedef struct pptx_ct_dgm_adj_s {
    pptx_uint idx;
    pptx_double val;
    int32_t index;
} pptx_ct_dgm_adj;

pptx_ct_dgm_adj *
pptx_ct_dgm_adj_new(xmlNode *node)
{
    pptx_ct_dgm_adj *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->idx = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "idx");
    obj->val = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_dgm_adj_get_idx(const pptx_ct_dgm_adj *const obj)
{
    return obj->idx;
}

pptx_double 
pptx_ct_dgm_adj_get_val(const pptx_ct_dgm_adj *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_dgm_adj_get_index(pptx_ct_dgm_adj *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_adj_free(pptx_ct_dgm_adj *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
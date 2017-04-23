#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tliterate-interval-time.h>
/* Imported internal stuff */
#include <private/pptx-st-tltime-indefinite.h>

typedef struct pptx_ct_p_tliterate_interval_time_s {
    pptx_st_tltime_indefinite_token_enum val;
    int32_t index;
} pptx_ct_p_tliterate_interval_time;

pptx_ct_p_tliterate_interval_time *
pptx_ct_p_tliterate_interval_time_new(xmlNode *node)
{
    pptx_ct_p_tliterate_interval_time *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_tltime_indefinite(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_tltime_indefinite_token_enum 
pptx_ct_p_tliterate_interval_time_get_val(const pptx_ct_p_tliterate_interval_time *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_p_tliterate_interval_time_get_index(pptx_ct_p_tliterate_interval_time *obj)
{
    return obj->index;
}

void
pptx_ct_p_tliterate_interval_time_free(pptx_ct_p_tliterate_interval_time *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
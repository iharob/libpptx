#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-grouping.h>
/* Imported internal stuff */
#include <private/pptx-st-grouping.h>

typedef struct pptx_ct_a_grouping_s {
    pptx_st_grouping_text_enum val;
    int32_t index;
} pptx_ct_a_grouping;

pptx_ct_a_grouping *
pptx_ct_a_grouping_new(xmlNode *node)
{
    pptx_ct_a_grouping *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_grouping(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_grouping_text_enum 
pptx_ct_a_grouping_get_val(const pptx_ct_a_grouping *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_grouping_get_index(pptx_ct_a_grouping *obj)
{
    return obj->index;
}

void
pptx_ct_a_grouping_free(pptx_ct_a_grouping *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
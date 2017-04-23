#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-legend-pos.h>
/* Imported internal stuff */
#include <private/pptx-st-legend-pos.h>

typedef struct pptx_ct_a_legend_pos_s {
    pptx_st_legend_pos_text_enum val;
    int32_t index;
} pptx_ct_a_legend_pos;

pptx_ct_a_legend_pos *
pptx_ct_a_legend_pos_new(xmlNode *node)
{
    pptx_ct_a_legend_pos *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_legend_pos(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_legend_pos_text_enum 
pptx_ct_a_legend_pos_get_val(const pptx_ct_a_legend_pos *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_legend_pos_get_index(pptx_ct_a_legend_pos *obj)
{
    return obj->index;
}

void
pptx_ct_a_legend_pos_free(pptx_ct_a_legend_pos *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-tick-mark.h>
/* Imported internal stuff */
#include <private/pptx-st-tick-mark.h>

typedef struct pptx_ct_a_tick_mark_s {
    pptx_st_tick_mark_text_enum val;
    int32_t index;
} pptx_ct_a_tick_mark;

pptx_ct_a_tick_mark *
pptx_ct_a_tick_mark_new(xmlNode *node)
{
    pptx_ct_a_tick_mark *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_tick_mark(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_tick_mark_text_enum 
pptx_ct_a_tick_mark_get_val(const pptx_ct_a_tick_mark *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_tick_mark_get_index(pptx_ct_a_tick_mark *obj)
{
    return obj->index;
}

void
pptx_ct_a_tick_mark_free(pptx_ct_a_tick_mark *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
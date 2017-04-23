#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-layout-mode.h>
/* Imported internal stuff */
#include <private/pptx-st-layout-mode.h>

typedef struct pptx_ct_a_layout_mode_s {
    pptx_st_layout_mode_text_enum val;
    int32_t index;
} pptx_ct_a_layout_mode;

pptx_ct_a_layout_mode *
pptx_ct_a_layout_mode_new(xmlNode *node)
{
    pptx_ct_a_layout_mode *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_layout_mode(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_layout_mode_text_enum 
pptx_ct_a_layout_mode_get_val(const pptx_ct_a_layout_mode *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_layout_mode_get_index(pptx_ct_a_layout_mode *obj)
{
    return obj->index;
}

void
pptx_ct_a_layout_mode_free(pptx_ct_a_layout_mode *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
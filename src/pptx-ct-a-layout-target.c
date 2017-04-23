#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-layout-target.h>
/* Imported internal stuff */
#include <private/pptx-st-layout-target.h>

typedef struct pptx_ct_a_layout_target_s {
    pptx_st_layout_target_text_enum val;
    int32_t index;
} pptx_ct_a_layout_target;

pptx_ct_a_layout_target *
pptx_ct_a_layout_target_new(xmlNode *node)
{
    pptx_ct_a_layout_target *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_layout_target(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_layout_target_text_enum 
pptx_ct_a_layout_target_get_val(const pptx_ct_a_layout_target *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_layout_target_get_index(pptx_ct_a_layout_target *obj)
{
    return obj->index;
}

void
pptx_ct_a_layout_target_free(pptx_ct_a_layout_target *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
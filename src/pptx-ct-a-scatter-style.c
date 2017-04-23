#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-scatter-style.h>
/* Imported internal stuff */
#include <private/pptx-st-scatter-style.h>

typedef struct pptx_ct_a_scatter_style_s {
    pptx_st_scatter_style_text_enum val;
    int32_t index;
} pptx_ct_a_scatter_style;

pptx_ct_a_scatter_style *
pptx_ct_a_scatter_style_new(xmlNode *node)
{
    pptx_ct_a_scatter_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_scatter_style(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_scatter_style_text_enum 
pptx_ct_a_scatter_style_get_val(const pptx_ct_a_scatter_style *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_scatter_style_get_index(pptx_ct_a_scatter_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_scatter_style_free(pptx_ct_a_scatter_style *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
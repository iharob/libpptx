#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-trendline-type.h>
/* Imported internal stuff */
#include <private/pptx-st-trendline-type.h>

typedef struct pptx_ct_a_trendline_type_s {
    pptx_st_trendline_type_text_enum val;
    int32_t index;
} pptx_ct_a_trendline_type;

pptx_ct_a_trendline_type *
pptx_ct_a_trendline_type_new(xmlNode *node)
{
    pptx_ct_a_trendline_type *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_trendline_type(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_trendline_type_text_enum 
pptx_ct_a_trendline_type_get_val(const pptx_ct_a_trendline_type *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_trendline_type_get_index(pptx_ct_a_trendline_type *obj)
{
    return obj->index;
}

void
pptx_ct_a_trendline_type_free(pptx_ct_a_trendline_type *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
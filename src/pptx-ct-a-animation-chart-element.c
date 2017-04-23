#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-animation-chart-element.h>
/* Imported internal stuff */
#include <private/pptx-st-chart-build-step.h>

typedef struct pptx_ct_a_animation_chart_element_s {
    pptx_int series_idx;
    pptx_int category_idx;
    pptx_st_chart_build_step_token_enum bld_step;
    int32_t index;
} pptx_ct_a_animation_chart_element;

pptx_ct_a_animation_chart_element *
pptx_ct_a_animation_chart_element_new(xmlNode *node)
{
    pptx_ct_a_animation_chart_element *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->series_idx = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "seriesIdx");
    obj->category_idx = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "categoryIdx");
    obj->bld_step = pptx_get_st_chart_build_step(node, (const xmlChar *) "bldStep");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_a_animation_chart_element_get_series_idx(const pptx_ct_a_animation_chart_element *const obj)
{
    return obj->series_idx;
}

pptx_int 
pptx_ct_a_animation_chart_element_get_category_idx(const pptx_ct_a_animation_chart_element *const obj)
{
    return obj->category_idx;
}

pptx_st_chart_build_step_token_enum 
pptx_ct_a_animation_chart_element_get_bld_step(const pptx_ct_a_animation_chart_element *const obj)
{
    return obj->bld_step;
}

int32_t
pptx_ct_a_animation_chart_element_get_index(pptx_ct_a_animation_chart_element *obj)
{
    return obj->index;
}

void
pptx_ct_a_animation_chart_element_free(pptx_ct_a_animation_chart_element *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-animation-chart-build-properties.h>
/* Imported internal stuff */
#include <private/pptx-st-animation-chart-only-build-type.h>

typedef struct pptx_ct_a_animation_chart_build_properties_s {
    pptx_st_animation_chart_only_build_type_token_enum bld;
    pptx_bool anim_bg;
    int32_t index;
} pptx_ct_a_animation_chart_build_properties;

pptx_ct_a_animation_chart_build_properties *
pptx_ct_a_animation_chart_build_properties_new(xmlNode *node)
{
    pptx_ct_a_animation_chart_build_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->bld = pptx_get_st_animation_chart_only_build_type(node, (const xmlChar *) "bld");
    obj->anim_bg = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "animBg");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_animation_chart_only_build_type_token_enum 
pptx_ct_a_animation_chart_build_properties_get_bld(const pptx_ct_a_animation_chart_build_properties *const obj)
{
    return obj->bld;
}

pptx_bool 
pptx_ct_a_animation_chart_build_properties_get_anim_bg(const pptx_ct_a_animation_chart_build_properties *const obj)
{
    return obj->anim_bg;
}

int32_t
pptx_ct_a_animation_chart_build_properties_get_index(pptx_ct_a_animation_chart_build_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_animation_chart_build_properties_free(pptx_ct_a_animation_chart_build_properties *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
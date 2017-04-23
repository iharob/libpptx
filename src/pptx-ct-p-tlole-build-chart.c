#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlole-build-chart.h>
/* Imported internal stuff */
#include <private/pptx-st-tlole-chart-build-type.h>

typedef struct pptx_ct_p_tlole_build_chart_s {
    pptx_uint spid;
    pptx_uint grp_id;
    pptx_bool ui_expand;
    pptx_st_tlole_chart_build_type_token_enum bld;
    pptx_bool anim_bg;
    int32_t index;
} pptx_ct_p_tlole_build_chart;

pptx_ct_p_tlole_build_chart *
pptx_ct_p_tlole_build_chart_new(xmlNode *node)
{
    pptx_ct_p_tlole_build_chart *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->spid = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "spid");
    obj->grp_id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "grpId");
    obj->ui_expand = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "uiExpand");
    obj->bld = pptx_get_st_tlole_chart_build_type(node, (const xmlChar *) "bld");
    obj->anim_bg = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "animBg");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_p_tlole_build_chart_get_spid(const pptx_ct_p_tlole_build_chart *const obj)
{
    return obj->spid;
}

pptx_uint 
pptx_ct_p_tlole_build_chart_get_grp_id(const pptx_ct_p_tlole_build_chart *const obj)
{
    return obj->grp_id;
}

pptx_bool 
pptx_ct_p_tlole_build_chart_get_ui_expand(const pptx_ct_p_tlole_build_chart *const obj)
{
    return obj->ui_expand;
}

pptx_st_tlole_chart_build_type_token_enum 
pptx_ct_p_tlole_build_chart_get_bld(const pptx_ct_p_tlole_build_chart *const obj)
{
    return obj->bld;
}

pptx_bool 
pptx_ct_p_tlole_build_chart_get_anim_bg(const pptx_ct_p_tlole_build_chart *const obj)
{
    return obj->anim_bg;
}

int32_t
pptx_ct_p_tlole_build_chart_get_index(pptx_ct_p_tlole_build_chart *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlole_build_chart_free(pptx_ct_p_tlole_build_chart *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlole-chart-target-element.h>
/* Imported internal stuff */
#include <private/pptx-st-tlchart-subelement-type.h>

typedef struct pptx_ct_p_tlole_chart_target_element_s {
    pptx_st_tlchart_subelement_type_token_enum type;
    pptx_uint lvl;
    int32_t index;
} pptx_ct_p_tlole_chart_target_element;

pptx_ct_p_tlole_chart_target_element *
pptx_ct_p_tlole_chart_target_element_new(xmlNode *node)
{
    pptx_ct_p_tlole_chart_target_element *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->type = pptx_get_st_tlchart_subelement_type(node, (const xmlChar *) "type");
    obj->lvl = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "lvl");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_tlchart_subelement_type_token_enum 
pptx_ct_p_tlole_chart_target_element_get_type(const pptx_ct_p_tlole_chart_target_element *const obj)
{
    return obj->type;
}

pptx_uint 
pptx_ct_p_tlole_chart_target_element_get_lvl(const pptx_ct_p_tlole_chart_target_element *const obj)
{
    return obj->lvl;
}

int32_t
pptx_ct_p_tlole_chart_target_element_get_index(pptx_ct_p_tlole_chart_target_element *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlole_chart_target_element_free(pptx_ct_p_tlole_chart_target_element *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}
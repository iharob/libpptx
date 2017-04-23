#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlanimate-behavior.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>
#include <private/pptx-ct-p-tltime-animate-value-list.h>
#include <private/pptx-st-tlanimate-behavior-calc-mode.h>
#include <private/pptx-st-tlanimate-behavior-value-type.h>

typedef struct pptx_ct_p_tlanimate_behavior_s {
    pptx_ct_p_tlcommon_behavior_data *c_bhvr;
    pptx_ct_p_tltime_animate_value_list *tav_lst;
    pptx_string by;
    pptx_string from;
    pptx_string to;
    pptx_st_tlanimate_behavior_calc_mode_token_enum calcmode;
    pptx_st_tlanimate_behavior_value_type_token_enum value_type;
    int32_t index;
} pptx_ct_p_tlanimate_behavior;

pptx_ct_p_tlanimate_behavior *
pptx_ct_p_tlanimate_behavior_new(xmlNode *node)
{
    pptx_ct_p_tlanimate_behavior *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cBhvr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_bhvr = NULL;
        } else {
            obj->c_bhvr = pptx_ct_p_tlcommon_behavior_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_bhvr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tavLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tav_lst = NULL;
        } else {
            obj->tav_lst = pptx_ct_p_tltime_animate_value_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tav_lst = NULL;
    }
    obj->by = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "by");
    obj->from = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "from");
    obj->to = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "to");
    obj->calcmode = pptx_get_st_tlanimate_behavior_calc_mode(node, (const xmlChar *) "calcmode");
    obj->value_type = pptx_get_st_tlanimate_behavior_value_type(node, (const xmlChar *) "valueType");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlanimate_behavior_get_c_bhvr(const pptx_ct_p_tlanimate_behavior *const obj)
{
    return obj->c_bhvr;
}

pptx_ct_p_tltime_animate_value_list *
pptx_ct_p_tlanimate_behavior_get_tav_lst(const pptx_ct_p_tlanimate_behavior *const obj)
{
    return obj->tav_lst;
}

pptx_string 
pptx_ct_p_tlanimate_behavior_get_by(const pptx_ct_p_tlanimate_behavior *const obj)
{
    return obj->by;
}

pptx_string 
pptx_ct_p_tlanimate_behavior_get_from(const pptx_ct_p_tlanimate_behavior *const obj)
{
    return obj->from;
}

pptx_string 
pptx_ct_p_tlanimate_behavior_get_to(const pptx_ct_p_tlanimate_behavior *const obj)
{
    return obj->to;
}

pptx_st_tlanimate_behavior_calc_mode_token_enum 
pptx_ct_p_tlanimate_behavior_get_calcmode(const pptx_ct_p_tlanimate_behavior *const obj)
{
    return obj->calcmode;
}

pptx_st_tlanimate_behavior_value_type_token_enum 
pptx_ct_p_tlanimate_behavior_get_value_type(const pptx_ct_p_tlanimate_behavior *const obj)
{
    return obj->value_type;
}

int32_t
pptx_ct_p_tlanimate_behavior_get_index(pptx_ct_p_tlanimate_behavior *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlanimate_behavior_free(pptx_ct_p_tlanimate_behavior *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_behavior_data_free(obj->c_bhvr);
    pptx_ct_p_tltime_animate_value_list_free(obj->tav_lst);
    xmlFree(obj->by);
    xmlFree(obj->from);
    xmlFree(obj->to);
    free(obj);
}
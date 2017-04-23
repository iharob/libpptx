#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-time-node-data.h>
#include <private/pptx-ct-p-tltime-target-element.h>
#include <private/pptx-ct-p-tlbehavior-attribute-name-list.h>
#include <private/pptx-st-tlbehavior-additive-type.h>
#include <private/pptx-st-tlbehavior-accumulate-type.h>
#include <private/pptx-st-tlbehavior-transform-type.h>
#include <private/pptx-st-tlbehavior-override-type.h>

typedef struct pptx_ct_p_tlcommon_behavior_data_s {
    pptx_ct_p_tlcommon_time_node_data *c_tn;
    pptx_ct_p_tltime_target_element *tgt_el;
    pptx_ct_p_tlbehavior_attribute_name_list *attr_name_lst;
    pptx_st_tlbehavior_additive_type_token_enum additive;
    pptx_st_tlbehavior_accumulate_type_token_enum accumulate;
    pptx_st_tlbehavior_transform_type_token_enum xfrm_type;
    pptx_string from;
    pptx_string to;
    pptx_string by;
    pptx_string rctx;
    pptx_st_tlbehavior_override_type_token_enum override;
    int32_t index;
} pptx_ct_p_tlcommon_behavior_data;

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlcommon_behavior_data_new(xmlNode *node)
{
    pptx_ct_p_tlcommon_behavior_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cTn");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_tn = NULL;
        } else {
            obj->c_tn = pptx_ct_p_tlcommon_time_node_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_tn = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tgtEl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tgt_el = NULL;
        } else {
            obj->tgt_el = pptx_ct_p_tltime_target_element_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tgt_el = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:attrNameLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->attr_name_lst = NULL;
        } else {
            obj->attr_name_lst = pptx_ct_p_tlbehavior_attribute_name_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->attr_name_lst = NULL;
    }
    obj->additive = pptx_get_st_tlbehavior_additive_type(node, (const xmlChar *) "additive");
    obj->accumulate = pptx_get_st_tlbehavior_accumulate_type(node, (const xmlChar *) "accumulate");
    obj->xfrm_type = pptx_get_st_tlbehavior_transform_type(node, (const xmlChar *) "xfrmType");
    obj->from = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "from");
    obj->to = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "to");
    obj->by = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "by");
    obj->rctx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "rctx");
    obj->override = pptx_get_st_tlbehavior_override_type(node, (const xmlChar *) "override");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_time_node_data *
pptx_ct_p_tlcommon_behavior_data_get_c_tn(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->c_tn;
}

pptx_ct_p_tltime_target_element *
pptx_ct_p_tlcommon_behavior_data_get_tgt_el(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->tgt_el;
}

pptx_ct_p_tlbehavior_attribute_name_list *
pptx_ct_p_tlcommon_behavior_data_get_attr_name_lst(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->attr_name_lst;
}

pptx_st_tlbehavior_additive_type_token_enum 
pptx_ct_p_tlcommon_behavior_data_get_additive(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->additive;
}

pptx_st_tlbehavior_accumulate_type_token_enum 
pptx_ct_p_tlcommon_behavior_data_get_accumulate(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->accumulate;
}

pptx_st_tlbehavior_transform_type_token_enum 
pptx_ct_p_tlcommon_behavior_data_get_xfrm_type(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->xfrm_type;
}

pptx_string 
pptx_ct_p_tlcommon_behavior_data_get_from(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->from;
}

pptx_string 
pptx_ct_p_tlcommon_behavior_data_get_to(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->to;
}

pptx_string 
pptx_ct_p_tlcommon_behavior_data_get_by(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->by;
}

pptx_string 
pptx_ct_p_tlcommon_behavior_data_get_rctx(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->rctx;
}

pptx_st_tlbehavior_override_type_token_enum 
pptx_ct_p_tlcommon_behavior_data_get_override(const pptx_ct_p_tlcommon_behavior_data *const obj)
{
    return obj->override;
}

int32_t
pptx_ct_p_tlcommon_behavior_data_get_index(pptx_ct_p_tlcommon_behavior_data *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlcommon_behavior_data_free(pptx_ct_p_tlcommon_behavior_data *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_time_node_data_free(obj->c_tn);
    pptx_ct_p_tltime_target_element_free(obj->tgt_el);
    pptx_ct_p_tlbehavior_attribute_name_list_free(obj->attr_name_lst);
    xmlFree(obj->from);
    xmlFree(obj->to);
    xmlFree(obj->by);
    xmlFree(obj->rctx);
    free(obj);
}
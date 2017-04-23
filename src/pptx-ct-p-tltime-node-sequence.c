#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltime-node-sequence.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-time-node-data.h>
#include <private/pptx-ct-p-tltime-condition-list.h>
#include <private/pptx-st-tlprevious-action-type.h>
#include <private/pptx-st-tlnext-action-type.h>

typedef struct pptx_ct_p_tltime_node_sequence_s {
    pptx_ct_p_tlcommon_time_node_data *c_tn;
    pptx_ct_p_tltime_condition_list *prev_cond_lst;
    pptx_ct_p_tltime_condition_list *next_cond_lst;
    pptx_bool concurrent;
    pptx_st_tlprevious_action_type_token_enum prev_ac;
    pptx_st_tlnext_action_type_token_enum next_ac;
    int32_t index;
} pptx_ct_p_tltime_node_sequence;

pptx_ct_p_tltime_node_sequence *
pptx_ct_p_tltime_node_sequence_new(xmlNode *node)
{
    pptx_ct_p_tltime_node_sequence *obj;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:prevCondLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->prev_cond_lst = NULL;
        } else {
            obj->prev_cond_lst = pptx_ct_p_tltime_condition_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->prev_cond_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:nextCondLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->next_cond_lst = NULL;
        } else {
            obj->next_cond_lst = pptx_ct_p_tltime_condition_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->next_cond_lst = NULL;
    }
    obj->concurrent = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "concurrent");
    obj->prev_ac = pptx_get_st_tlprevious_action_type(node, (const xmlChar *) "prevAc");
    obj->next_ac = pptx_get_st_tlnext_action_type(node, (const xmlChar *) "nextAc");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_time_node_data *
pptx_ct_p_tltime_node_sequence_get_c_tn(const pptx_ct_p_tltime_node_sequence *const obj)
{
    return obj->c_tn;
}

pptx_ct_p_tltime_condition_list *
pptx_ct_p_tltime_node_sequence_get_prev_cond_lst(const pptx_ct_p_tltime_node_sequence *const obj)
{
    return obj->prev_cond_lst;
}

pptx_ct_p_tltime_condition_list *
pptx_ct_p_tltime_node_sequence_get_next_cond_lst(const pptx_ct_p_tltime_node_sequence *const obj)
{
    return obj->next_cond_lst;
}

pptx_bool 
pptx_ct_p_tltime_node_sequence_get_concurrent(const pptx_ct_p_tltime_node_sequence *const obj)
{
    return obj->concurrent;
}

pptx_st_tlprevious_action_type_token_enum 
pptx_ct_p_tltime_node_sequence_get_prev_ac(const pptx_ct_p_tltime_node_sequence *const obj)
{
    return obj->prev_ac;
}

pptx_st_tlnext_action_type_token_enum 
pptx_ct_p_tltime_node_sequence_get_next_ac(const pptx_ct_p_tltime_node_sequence *const obj)
{
    return obj->next_ac;
}

int32_t
pptx_ct_p_tltime_node_sequence_get_index(pptx_ct_p_tltime_node_sequence *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltime_node_sequence_free(pptx_ct_p_tltime_node_sequence *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_time_node_data_free(obj->c_tn);
    pptx_ct_p_tltime_condition_list_free(obj->prev_cond_lst);
    pptx_ct_p_tltime_condition_list_free(obj->next_cond_lst);
    free(obj);
}
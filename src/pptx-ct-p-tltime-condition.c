#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltime-condition.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tltime-target-element.h>
#include <private/pptx-ct-p-tltrigger-time-node-id.h>
#include <private/pptx-ct-p-tltrigger-runtime-node.h>
#include <private/pptx-st-tltrigger-event.h>
#include <private/pptx-st-tltime-indefinite.h>

typedef struct pptx_ct_p_tltime_condition_s {
    pptx_ct_p_tltime_target_element *tgt_el;
    pptx_ct_p_tltrigger_time_node_id *tn;
    pptx_ct_p_tltrigger_runtime_node *rtn;
    pptx_st_tltrigger_event_token_enum evt;
    pptx_st_tltime_indefinite_token_enum delay;
    int32_t index;
} pptx_ct_p_tltime_condition;

pptx_ct_p_tltime_condition *
pptx_ct_p_tltime_condition_new(xmlNode *node)
{
    pptx_ct_p_tltime_condition *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tn");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tn = NULL;
        } else {
            obj->tn = pptx_ct_p_tltrigger_time_node_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tn = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:rtn");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->rtn = NULL;
        } else {
            obj->rtn = pptx_ct_p_tltrigger_runtime_node_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rtn = NULL;
    }
    obj->evt = pptx_get_st_tltrigger_event(node, (const xmlChar *) "evt");
    obj->delay = pptx_get_st_tltime_indefinite(node, (const xmlChar *) "delay");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tltime_target_element *
pptx_ct_p_tltime_condition_get_tgt_el(const pptx_ct_p_tltime_condition *const obj)
{
    return obj->tgt_el;
}

pptx_ct_p_tltrigger_time_node_id *
pptx_ct_p_tltime_condition_get_tn(const pptx_ct_p_tltime_condition *const obj)
{
    return obj->tn;
}

pptx_ct_p_tltrigger_runtime_node *
pptx_ct_p_tltime_condition_get_rtn(const pptx_ct_p_tltime_condition *const obj)
{
    return obj->rtn;
}

pptx_st_tltrigger_event_token_enum 
pptx_ct_p_tltime_condition_get_evt(const pptx_ct_p_tltime_condition *const obj)
{
    return obj->evt;
}

pptx_st_tltime_indefinite_token_enum 
pptx_ct_p_tltime_condition_get_delay(const pptx_ct_p_tltime_condition *const obj)
{
    return obj->delay;
}

int32_t
pptx_ct_p_tltime_condition_get_index(pptx_ct_p_tltime_condition *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltime_condition_free(pptx_ct_p_tltime_condition *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tltime_target_element_free(obj->tgt_el);
    pptx_ct_p_tltrigger_time_node_id_free(obj->tn);
    pptx_ct_p_tltrigger_runtime_node_free(obj->rtn);
    free(obj);
}
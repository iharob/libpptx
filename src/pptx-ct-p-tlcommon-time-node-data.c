#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlcommon-time-node-data.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tltime-condition-list.h>
#include <private/pptx-ct-p-tltime-condition.h>
#include <private/pptx-ct-p-tliterate-data.h>
#include <private/pptx-ct-p-time-node-list.h>
#include <private/pptx-st-tltime-node-preset-class-type.h>
#include <private/pptx-st-tltime-indefinite.h>
#include <private/pptx-st-tltime-node-restart-type.h>
#include <private/pptx-st-tltime-node-fill-type.h>
#include <private/pptx-st-tltime-node-sync-type.h>
#include <private/pptx-st-tltime-node-master-relation.h>
#include <private/pptx-st-tltime-node-type.h>

typedef struct pptx_ct_p_tlcommon_time_node_data_s {
    pptx_ct_p_tltime_condition_list *st_cond_lst;
    pptx_ct_p_tltime_condition_list *end_cond_lst;
    pptx_ct_p_tltime_condition *end_sync;
    pptx_ct_p_tliterate_data *iterate;
    pptx_ct_p_time_node_list *child_tn_lst;
    pptx_ct_p_time_node_list *sub_tn_lst;
    pptx_uint id;
    pptx_int preset_id;
    pptx_st_tltime_node_preset_class_type_token_enum preset_class;
    pptx_int preset_subtype;
    pptx_st_tltime_indefinite_token_enum dur;
    pptx_st_tltime_indefinite_token_enum repeat_count;
    pptx_st_tltime_indefinite_token_enum repeat_dur;
    pptx_string spd;
    pptx_string accel;
    pptx_string decel;
    pptx_bool auto_rev;
    pptx_st_tltime_node_restart_type_token_enum restart;
    pptx_st_tltime_node_fill_type_token_enum fill;
    pptx_st_tltime_node_sync_type_token_enum sync_behavior;
    pptx_string tm_filter;
    pptx_string evt_filter;
    pptx_bool display;
    pptx_st_tltime_node_master_relation_token_enum master_rel;
    pptx_int bld_lvl;
    pptx_uint grp_id;
    pptx_bool after_effect;
    pptx_st_tltime_node_type_token_enum node_type;
    pptx_bool node_ph;
    int32_t index;
} pptx_ct_p_tlcommon_time_node_data;

pptx_ct_p_tlcommon_time_node_data *
pptx_ct_p_tlcommon_time_node_data_new(xmlNode *node)
{
    pptx_ct_p_tlcommon_time_node_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:stCondLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->st_cond_lst = NULL;
        } else {
            obj->st_cond_lst = pptx_ct_p_tltime_condition_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->st_cond_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:endCondLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->end_cond_lst = NULL;
        } else {
            obj->end_cond_lst = pptx_ct_p_tltime_condition_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->end_cond_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:endSync");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->end_sync = NULL;
        } else {
            obj->end_sync = pptx_ct_p_tltime_condition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->end_sync = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:iterate");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->iterate = NULL;
        } else {
            obj->iterate = pptx_ct_p_tliterate_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->iterate = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:childTnLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->child_tn_lst = NULL;
        } else {
            obj->child_tn_lst = pptx_ct_p_time_node_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->child_tn_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:subTnLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sub_tn_lst = NULL;
        } else {
            obj->sub_tn_lst = pptx_ct_p_time_node_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sub_tn_lst = NULL;
    }
    obj->id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "id");
    obj->preset_id = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "presetID");
    obj->preset_class = pptx_get_st_tltime_node_preset_class_type(node, (const xmlChar *) "presetClass");
    obj->preset_subtype = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "presetSubtype");
    obj->dur = pptx_get_st_tltime_indefinite(node, (const xmlChar *) "dur");
    obj->repeat_count = pptx_get_st_tltime_indefinite(node, (const xmlChar *) "repeatCount");
    obj->repeat_dur = pptx_get_st_tltime_indefinite(node, (const xmlChar *) "repeatDur");
    obj->spd = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "spd");
    obj->accel = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "accel");
    obj->decel = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "decel");
    obj->auto_rev = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "autoRev");
    obj->restart = pptx_get_st_tltime_node_restart_type(node, (const xmlChar *) "restart");
    obj->fill = pptx_get_st_tltime_node_fill_type(node, (const xmlChar *) "fill");
    obj->sync_behavior = pptx_get_st_tltime_node_sync_type(node, (const xmlChar *) "syncBehavior");
    obj->tm_filter = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "tmFilter");
    obj->evt_filter = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "evtFilter");
    obj->display = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "display");
    obj->master_rel = pptx_get_st_tltime_node_master_relation(node, (const xmlChar *) "masterRel");
    obj->bld_lvl = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "bldLvl");
    obj->grp_id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "grpId");
    obj->after_effect = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "afterEffect");
    obj->node_type = pptx_get_st_tltime_node_type(node, (const xmlChar *) "nodeType");
    obj->node_ph = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "nodePh");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tltime_condition_list *
pptx_ct_p_tlcommon_time_node_data_get_st_cond_lst(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->st_cond_lst;
}

pptx_ct_p_tltime_condition_list *
pptx_ct_p_tlcommon_time_node_data_get_end_cond_lst(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->end_cond_lst;
}

pptx_ct_p_tltime_condition *
pptx_ct_p_tlcommon_time_node_data_get_end_sync(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->end_sync;
}

pptx_ct_p_tliterate_data *
pptx_ct_p_tlcommon_time_node_data_get_iterate(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->iterate;
}

pptx_ct_p_time_node_list *
pptx_ct_p_tlcommon_time_node_data_get_child_tn_lst(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->child_tn_lst;
}

pptx_ct_p_time_node_list *
pptx_ct_p_tlcommon_time_node_data_get_sub_tn_lst(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->sub_tn_lst;
}

pptx_uint 
pptx_ct_p_tlcommon_time_node_data_get_id(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->id;
}

pptx_int 
pptx_ct_p_tlcommon_time_node_data_get_preset_id(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->preset_id;
}

pptx_st_tltime_node_preset_class_type_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_preset_class(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->preset_class;
}

pptx_int 
pptx_ct_p_tlcommon_time_node_data_get_preset_subtype(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->preset_subtype;
}

pptx_st_tltime_indefinite_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_dur(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->dur;
}

pptx_st_tltime_indefinite_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_repeat_count(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->repeat_count;
}

pptx_st_tltime_indefinite_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_repeat_dur(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->repeat_dur;
}

pptx_string 
pptx_ct_p_tlcommon_time_node_data_get_spd(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->spd;
}

pptx_string 
pptx_ct_p_tlcommon_time_node_data_get_accel(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->accel;
}

pptx_string 
pptx_ct_p_tlcommon_time_node_data_get_decel(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->decel;
}

pptx_bool 
pptx_ct_p_tlcommon_time_node_data_get_auto_rev(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->auto_rev;
}

pptx_st_tltime_node_restart_type_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_restart(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->restart;
}

pptx_st_tltime_node_fill_type_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_fill(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->fill;
}

pptx_st_tltime_node_sync_type_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_sync_behavior(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->sync_behavior;
}

pptx_string 
pptx_ct_p_tlcommon_time_node_data_get_tm_filter(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->tm_filter;
}

pptx_string 
pptx_ct_p_tlcommon_time_node_data_get_evt_filter(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->evt_filter;
}

pptx_bool 
pptx_ct_p_tlcommon_time_node_data_get_display(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->display;
}

pptx_st_tltime_node_master_relation_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_master_rel(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->master_rel;
}

pptx_int 
pptx_ct_p_tlcommon_time_node_data_get_bld_lvl(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->bld_lvl;
}

pptx_uint 
pptx_ct_p_tlcommon_time_node_data_get_grp_id(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->grp_id;
}

pptx_bool 
pptx_ct_p_tlcommon_time_node_data_get_after_effect(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->after_effect;
}

pptx_st_tltime_node_type_token_enum 
pptx_ct_p_tlcommon_time_node_data_get_node_type(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->node_type;
}

pptx_bool 
pptx_ct_p_tlcommon_time_node_data_get_node_ph(const pptx_ct_p_tlcommon_time_node_data *const obj)
{
    return obj->node_ph;
}

int32_t
pptx_ct_p_tlcommon_time_node_data_get_index(pptx_ct_p_tlcommon_time_node_data *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlcommon_time_node_data_free(pptx_ct_p_tlcommon_time_node_data *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tltime_condition_list_free(obj->st_cond_lst);
    pptx_ct_p_tltime_condition_list_free(obj->end_cond_lst);
    pptx_ct_p_tltime_condition_free(obj->end_sync);
    pptx_ct_p_tliterate_data_free(obj->iterate);
    pptx_ct_p_time_node_list_free(obj->child_tn_lst);
    pptx_ct_p_time_node_list_free(obj->sub_tn_lst);
    xmlFree(obj->spd);
    xmlFree(obj->accel);
    xmlFree(obj->decel);
    xmlFree(obj->tm_filter);
    xmlFree(obj->evt_filter);
    free(obj);
}
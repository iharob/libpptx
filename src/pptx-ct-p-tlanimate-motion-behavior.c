#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlanimate-motion-behavior.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>
#include <private/pptx-ct-p-tlpoint.h>
#include <private/pptx-st-tlanimate-motion-behavior-origin.h>
#include <private/pptx-st-tlanimate-motion-path-edit-mode.h>

typedef struct pptx_ct_p_tlanimate_motion_behavior_s {
    pptx_ct_p_tlcommon_behavior_data *c_bhvr;
    pptx_ct_p_tlpoint *by;
    pptx_ct_p_tlpoint *from;
    pptx_ct_p_tlpoint *to;
    pptx_ct_p_tlpoint *r_ctr;
    pptx_st_tlanimate_motion_behavior_origin_token_enum origin;
    pptx_string path;
    pptx_st_tlanimate_motion_path_edit_mode_token_enum path_edit_mode;
    pptx_int r_ang;
    pptx_string pts_types;
    int32_t index;
} pptx_ct_p_tlanimate_motion_behavior;

pptx_ct_p_tlanimate_motion_behavior *
pptx_ct_p_tlanimate_motion_behavior_new(xmlNode *node)
{
    pptx_ct_p_tlanimate_motion_behavior *obj;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:by");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->by = NULL;
        } else {
            obj->by = pptx_ct_p_tlpoint_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->by = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:from");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->from = NULL;
        } else {
            obj->from = pptx_ct_p_tlpoint_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->from = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:to");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->to = NULL;
        } else {
            obj->to = pptx_ct_p_tlpoint_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->to = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:rCtr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->r_ctr = NULL;
        } else {
            obj->r_ctr = pptx_ct_p_tlpoint_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->r_ctr = NULL;
    }
    obj->origin = pptx_get_st_tlanimate_motion_behavior_origin(node, (const xmlChar *) "origin");
    obj->path = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "path");
    obj->path_edit_mode = pptx_get_st_tlanimate_motion_path_edit_mode(node, (const xmlChar *) "pathEditMode");
    obj->r_ang = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "rAng");
    obj->pts_types = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "ptsTypes");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlanimate_motion_behavior_get_c_bhvr(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->c_bhvr;
}

pptx_ct_p_tlpoint *
pptx_ct_p_tlanimate_motion_behavior_get_by(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->by;
}

pptx_ct_p_tlpoint *
pptx_ct_p_tlanimate_motion_behavior_get_from(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->from;
}

pptx_ct_p_tlpoint *
pptx_ct_p_tlanimate_motion_behavior_get_to(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->to;
}

pptx_ct_p_tlpoint *
pptx_ct_p_tlanimate_motion_behavior_get_r_ctr(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->r_ctr;
}

pptx_st_tlanimate_motion_behavior_origin_token_enum 
pptx_ct_p_tlanimate_motion_behavior_get_origin(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->origin;
}

pptx_string 
pptx_ct_p_tlanimate_motion_behavior_get_path(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->path;
}

pptx_st_tlanimate_motion_path_edit_mode_token_enum 
pptx_ct_p_tlanimate_motion_behavior_get_path_edit_mode(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->path_edit_mode;
}

pptx_int 
pptx_ct_p_tlanimate_motion_behavior_get_r_ang(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->r_ang;
}

pptx_string 
pptx_ct_p_tlanimate_motion_behavior_get_pts_types(const pptx_ct_p_tlanimate_motion_behavior *const obj)
{
    return obj->pts_types;
}

int32_t
pptx_ct_p_tlanimate_motion_behavior_get_index(pptx_ct_p_tlanimate_motion_behavior *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlanimate_motion_behavior_free(pptx_ct_p_tlanimate_motion_behavior *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_behavior_data_free(obj->c_bhvr);
    pptx_ct_p_tlpoint_free(obj->by);
    pptx_ct_p_tlpoint_free(obj->from);
    pptx_ct_p_tlpoint_free(obj->to);
    pptx_ct_p_tlpoint_free(obj->r_ctr);
    xmlFree(obj->path);
    xmlFree(obj->pts_types);
    free(obj);
}
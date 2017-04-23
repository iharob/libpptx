#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlanimate-color-behavior.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>
#include <private/pptx-ct-p-tlby-animate-color-transform.h>
#include <private/pptx-ct-a-color.h>
#include <private/pptx-st-tlanimate-color-space.h>
#include <private/pptx-st-tlanimate-color-direction.h>

typedef struct pptx_ct_p_tlanimate_color_behavior_s {
    pptx_ct_p_tlcommon_behavior_data *c_bhvr;
    pptx_ct_p_tlby_animate_color_transform *by;
    pptx_ct_a_color *from;
    pptx_ct_a_color *to;
    pptx_st_tlanimate_color_space_token_enum clr_spc;
    pptx_st_tlanimate_color_direction_token_enum dir;
    int32_t index;
} pptx_ct_p_tlanimate_color_behavior;

pptx_ct_p_tlanimate_color_behavior *
pptx_ct_p_tlanimate_color_behavior_new(xmlNode *node)
{
    pptx_ct_p_tlanimate_color_behavior *obj;
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
            obj->by = pptx_ct_p_tlby_animate_color_transform_new(nodes->nodeTab[0]);
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
            obj->from = pptx_ct_a_color_new(nodes->nodeTab[0]);
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
            obj->to = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->to = NULL;
    }
    obj->clr_spc = pptx_get_st_tlanimate_color_space(node, (const xmlChar *) "clrSpc");
    obj->dir = pptx_get_st_tlanimate_color_direction(node, (const xmlChar *) "dir");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlanimate_color_behavior_get_c_bhvr(const pptx_ct_p_tlanimate_color_behavior *const obj)
{
    return obj->c_bhvr;
}

pptx_ct_p_tlby_animate_color_transform *
pptx_ct_p_tlanimate_color_behavior_get_by(const pptx_ct_p_tlanimate_color_behavior *const obj)
{
    return obj->by;
}

pptx_ct_a_color *
pptx_ct_p_tlanimate_color_behavior_get_from(const pptx_ct_p_tlanimate_color_behavior *const obj)
{
    return obj->from;
}

pptx_ct_a_color *
pptx_ct_p_tlanimate_color_behavior_get_to(const pptx_ct_p_tlanimate_color_behavior *const obj)
{
    return obj->to;
}

pptx_st_tlanimate_color_space_token_enum 
pptx_ct_p_tlanimate_color_behavior_get_clr_spc(const pptx_ct_p_tlanimate_color_behavior *const obj)
{
    return obj->clr_spc;
}

pptx_st_tlanimate_color_direction_token_enum 
pptx_ct_p_tlanimate_color_behavior_get_dir(const pptx_ct_p_tlanimate_color_behavior *const obj)
{
    return obj->dir;
}

int32_t
pptx_ct_p_tlanimate_color_behavior_get_index(pptx_ct_p_tlanimate_color_behavior *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlanimate_color_behavior_free(pptx_ct_p_tlanimate_color_behavior *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_behavior_data_free(obj->c_bhvr);
    pptx_ct_p_tlby_animate_color_transform_free(obj->by);
    pptx_ct_a_color_free(obj->from);
    pptx_ct_a_color_free(obj->to);
    free(obj);
}
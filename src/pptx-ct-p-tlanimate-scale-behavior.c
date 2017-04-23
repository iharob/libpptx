#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlanimate-scale-behavior.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>
#include <private/pptx-ct-p-tlpoint.h>

typedef struct pptx_ct_p_tlanimate_scale_behavior_s {
    pptx_ct_p_tlcommon_behavior_data *c_bhvr;
    pptx_ct_p_tlpoint *by;
    pptx_ct_p_tlpoint *from;
    pptx_ct_p_tlpoint *to;
    pptx_bool zoom_contents;
    int32_t index;
} pptx_ct_p_tlanimate_scale_behavior;

pptx_ct_p_tlanimate_scale_behavior *
pptx_ct_p_tlanimate_scale_behavior_new(xmlNode *node)
{
    pptx_ct_p_tlanimate_scale_behavior *obj;
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
    obj->zoom_contents = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "zoomContents");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlanimate_scale_behavior_get_c_bhvr(const pptx_ct_p_tlanimate_scale_behavior *const obj)
{
    return obj->c_bhvr;
}

pptx_ct_p_tlpoint *
pptx_ct_p_tlanimate_scale_behavior_get_by(const pptx_ct_p_tlanimate_scale_behavior *const obj)
{
    return obj->by;
}

pptx_ct_p_tlpoint *
pptx_ct_p_tlanimate_scale_behavior_get_from(const pptx_ct_p_tlanimate_scale_behavior *const obj)
{
    return obj->from;
}

pptx_ct_p_tlpoint *
pptx_ct_p_tlanimate_scale_behavior_get_to(const pptx_ct_p_tlanimate_scale_behavior *const obj)
{
    return obj->to;
}

pptx_bool 
pptx_ct_p_tlanimate_scale_behavior_get_zoom_contents(const pptx_ct_p_tlanimate_scale_behavior *const obj)
{
    return obj->zoom_contents;
}

int32_t
pptx_ct_p_tlanimate_scale_behavior_get_index(pptx_ct_p_tlanimate_scale_behavior *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlanimate_scale_behavior_free(pptx_ct_p_tlanimate_scale_behavior *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_behavior_data_free(obj->c_bhvr);
    pptx_ct_p_tlpoint_free(obj->by);
    pptx_ct_p_tlpoint_free(obj->from);
    pptx_ct_p_tlpoint_free(obj->to);
    free(obj);
}
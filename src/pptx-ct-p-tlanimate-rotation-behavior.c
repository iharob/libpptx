#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlanimate-rotation-behavior.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>

typedef struct pptx_ct_p_tlanimate_rotation_behavior_s {
    pptx_ct_p_tlcommon_behavior_data *c_bhvr;
    pptx_int by;
    pptx_int from;
    pptx_int to;
    int32_t index;
} pptx_ct_p_tlanimate_rotation_behavior;

pptx_ct_p_tlanimate_rotation_behavior *
pptx_ct_p_tlanimate_rotation_behavior_new(xmlNode *node)
{
    pptx_ct_p_tlanimate_rotation_behavior *obj;
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
    obj->by = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "by");
    obj->from = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "from");
    obj->to = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "to");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlanimate_rotation_behavior_get_c_bhvr(const pptx_ct_p_tlanimate_rotation_behavior *const obj)
{
    return obj->c_bhvr;
}

pptx_int 
pptx_ct_p_tlanimate_rotation_behavior_get_by(const pptx_ct_p_tlanimate_rotation_behavior *const obj)
{
    return obj->by;
}

pptx_int 
pptx_ct_p_tlanimate_rotation_behavior_get_from(const pptx_ct_p_tlanimate_rotation_behavior *const obj)
{
    return obj->from;
}

pptx_int 
pptx_ct_p_tlanimate_rotation_behavior_get_to(const pptx_ct_p_tlanimate_rotation_behavior *const obj)
{
    return obj->to;
}

int32_t
pptx_ct_p_tlanimate_rotation_behavior_get_index(pptx_ct_p_tlanimate_rotation_behavior *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlanimate_rotation_behavior_free(pptx_ct_p_tlanimate_rotation_behavior *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_behavior_data_free(obj->c_bhvr);
    free(obj);
}
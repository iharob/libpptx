#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlanimate-effect-behavior.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>
#include <private/pptx-ct-p-tlanim-variant.h>
#include <private/pptx-st-tlanimate-effect-transition.h>

typedef struct pptx_ct_p_tlanimate_effect_behavior_s {
    pptx_ct_p_tlcommon_behavior_data *c_bhvr;
    pptx_ct_p_tlanim_variant *progress;
    pptx_st_tlanimate_effect_transition_token_enum transition;
    pptx_string filter;
    pptx_string pr_lst;
    int32_t index;
} pptx_ct_p_tlanimate_effect_behavior;

pptx_ct_p_tlanimate_effect_behavior *
pptx_ct_p_tlanimate_effect_behavior_new(xmlNode *node)
{
    pptx_ct_p_tlanimate_effect_behavior *obj;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:progress");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->progress = NULL;
        } else {
            obj->progress = pptx_ct_p_tlanim_variant_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->progress = NULL;
    }
    obj->transition = pptx_get_st_tlanimate_effect_transition(node, (const xmlChar *) "transition");
    obj->filter = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "filter");
    obj->pr_lst = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "prLst");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlanimate_effect_behavior_get_c_bhvr(const pptx_ct_p_tlanimate_effect_behavior *const obj)
{
    return obj->c_bhvr;
}

pptx_ct_p_tlanim_variant *
pptx_ct_p_tlanimate_effect_behavior_get_progress(const pptx_ct_p_tlanimate_effect_behavior *const obj)
{
    return obj->progress;
}

pptx_st_tlanimate_effect_transition_token_enum 
pptx_ct_p_tlanimate_effect_behavior_get_transition(const pptx_ct_p_tlanimate_effect_behavior *const obj)
{
    return obj->transition;
}

pptx_string 
pptx_ct_p_tlanimate_effect_behavior_get_filter(const pptx_ct_p_tlanimate_effect_behavior *const obj)
{
    return obj->filter;
}

pptx_string 
pptx_ct_p_tlanimate_effect_behavior_get_pr_lst(const pptx_ct_p_tlanimate_effect_behavior *const obj)
{
    return obj->pr_lst;
}

int32_t
pptx_ct_p_tlanimate_effect_behavior_get_index(pptx_ct_p_tlanimate_effect_behavior *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlanimate_effect_behavior_free(pptx_ct_p_tlanimate_effect_behavior *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_behavior_data_free(obj->c_bhvr);
    pptx_ct_p_tlanim_variant_free(obj->progress);
    xmlFree(obj->filter);
    xmlFree(obj->pr_lst);
    free(obj);
}
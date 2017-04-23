#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlset-behavior.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>
#include <private/pptx-ct-p-tlanim-variant.h>

typedef struct pptx_ct_p_tlset_behavior_s {
    pptx_ct_p_tlcommon_behavior_data *c_bhvr;
    pptx_ct_p_tlanim_variant *to;
    int32_t index;
} pptx_ct_p_tlset_behavior;

pptx_ct_p_tlset_behavior *
pptx_ct_p_tlset_behavior_new(xmlNode *node)
{
    pptx_ct_p_tlset_behavior *obj;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:to");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->to = NULL;
        } else {
            obj->to = pptx_ct_p_tlanim_variant_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->to = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlset_behavior_get_c_bhvr(const pptx_ct_p_tlset_behavior *const obj)
{
    return obj->c_bhvr;
}

pptx_ct_p_tlanim_variant *
pptx_ct_p_tlset_behavior_get_to(const pptx_ct_p_tlset_behavior *const obj)
{
    return obj->to;
}

int32_t
pptx_ct_p_tlset_behavior_get_index(pptx_ct_p_tlset_behavior *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlset_behavior_free(pptx_ct_p_tlset_behavior *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_behavior_data_free(obj->c_bhvr);
    pptx_ct_p_tlanim_variant_free(obj->to);
    free(obj);
}
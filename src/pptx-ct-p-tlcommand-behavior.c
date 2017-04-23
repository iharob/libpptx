#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlcommand-behavior.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-behavior-data.h>
#include <private/pptx-st-tlcommand-type.h>

typedef struct pptx_ct_p_tlcommand_behavior_s {
    pptx_ct_p_tlcommon_behavior_data *c_bhvr;
    pptx_st_tlcommand_type_token_enum type;
    pptx_string cmd;
    int32_t index;
} pptx_ct_p_tlcommand_behavior;

pptx_ct_p_tlcommand_behavior *
pptx_ct_p_tlcommand_behavior_new(xmlNode *node)
{
    pptx_ct_p_tlcommand_behavior *obj;
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
    obj->type = pptx_get_st_tlcommand_type(node, (const xmlChar *) "type");
    obj->cmd = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "cmd");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_behavior_data *
pptx_ct_p_tlcommand_behavior_get_c_bhvr(const pptx_ct_p_tlcommand_behavior *const obj)
{
    return obj->c_bhvr;
}

pptx_st_tlcommand_type_token_enum 
pptx_ct_p_tlcommand_behavior_get_type(const pptx_ct_p_tlcommand_behavior *const obj)
{
    return obj->type;
}

pptx_string 
pptx_ct_p_tlcommand_behavior_get_cmd(const pptx_ct_p_tlcommand_behavior *const obj)
{
    return obj->cmd;
}

int32_t
pptx_ct_p_tlcommand_behavior_get_index(pptx_ct_p_tlcommand_behavior *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlcommand_behavior_free(pptx_ct_p_tlcommand_behavior *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_behavior_data_free(obj->c_bhvr);
    xmlFree(obj->cmd);
    free(obj);
}
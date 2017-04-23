#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlcommon-media-node-data.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-time-node-data.h>
#include <private/pptx-ct-p-tltime-target-element.h>

typedef struct pptx_ct_p_tlcommon_media_node_data_s {
    pptx_ct_p_tlcommon_time_node_data *c_tn;
    pptx_ct_p_tltime_target_element *tgt_el;
    pptx_string vol;
    pptx_bool mute;
    pptx_uint num_sld;
    pptx_bool show_when_stopped;
    int32_t index;
} pptx_ct_p_tlcommon_media_node_data;

pptx_ct_p_tlcommon_media_node_data *
pptx_ct_p_tlcommon_media_node_data_new(xmlNode *node)
{
    pptx_ct_p_tlcommon_media_node_data *obj;
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
    obj->vol = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "vol");
    obj->mute = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "mute");
    obj->num_sld = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "numSld");
    obj->show_when_stopped = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showWhenStopped");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_time_node_data *
pptx_ct_p_tlcommon_media_node_data_get_c_tn(const pptx_ct_p_tlcommon_media_node_data *const obj)
{
    return obj->c_tn;
}

pptx_ct_p_tltime_target_element *
pptx_ct_p_tlcommon_media_node_data_get_tgt_el(const pptx_ct_p_tlcommon_media_node_data *const obj)
{
    return obj->tgt_el;
}

pptx_string 
pptx_ct_p_tlcommon_media_node_data_get_vol(const pptx_ct_p_tlcommon_media_node_data *const obj)
{
    return obj->vol;
}

pptx_bool 
pptx_ct_p_tlcommon_media_node_data_get_mute(const pptx_ct_p_tlcommon_media_node_data *const obj)
{
    return obj->mute;
}

pptx_uint 
pptx_ct_p_tlcommon_media_node_data_get_num_sld(const pptx_ct_p_tlcommon_media_node_data *const obj)
{
    return obj->num_sld;
}

pptx_bool 
pptx_ct_p_tlcommon_media_node_data_get_show_when_stopped(const pptx_ct_p_tlcommon_media_node_data *const obj)
{
    return obj->show_when_stopped;
}

int32_t
pptx_ct_p_tlcommon_media_node_data_get_index(pptx_ct_p_tlcommon_media_node_data *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlcommon_media_node_data_free(pptx_ct_p_tlcommon_media_node_data *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_time_node_data_free(obj->c_tn);
    pptx_ct_p_tltime_target_element_free(obj->tgt_el);
    xmlFree(obj->vol);
    free(obj);
}
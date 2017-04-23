#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlmedia-node-audio.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-media-node-data.h>

typedef struct pptx_ct_p_tlmedia_node_audio_s {
    pptx_ct_p_tlcommon_media_node_data *c_media_node;
    pptx_bool is_narration;
    int32_t index;
} pptx_ct_p_tlmedia_node_audio;

pptx_ct_p_tlmedia_node_audio *
pptx_ct_p_tlmedia_node_audio_new(xmlNode *node)
{
    pptx_ct_p_tlmedia_node_audio *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cMediaNode");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_media_node = NULL;
        } else {
            obj->c_media_node = pptx_ct_p_tlcommon_media_node_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_media_node = NULL;
    }
    obj->is_narration = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "isNarration");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_media_node_data *
pptx_ct_p_tlmedia_node_audio_get_c_media_node(const pptx_ct_p_tlmedia_node_audio *const obj)
{
    return obj->c_media_node;
}

pptx_bool 
pptx_ct_p_tlmedia_node_audio_get_is_narration(const pptx_ct_p_tlmedia_node_audio *const obj)
{
    return obj->is_narration;
}

int32_t
pptx_ct_p_tlmedia_node_audio_get_index(pptx_ct_p_tlmedia_node_audio *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlmedia_node_audio_free(pptx_ct_p_tlmedia_node_audio *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_media_node_data_free(obj->c_media_node);
    free(obj);
}
#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlmedia-node-video.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-media-node-data.h>

typedef struct pptx_ct_p_tlmedia_node_video_s {
    pptx_ct_p_tlcommon_media_node_data *c_media_node;
    pptx_bool full_scrn;
    int32_t index;
} pptx_ct_p_tlmedia_node_video;

pptx_ct_p_tlmedia_node_video *
pptx_ct_p_tlmedia_node_video_new(xmlNode *node)
{
    pptx_ct_p_tlmedia_node_video *obj;
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
    obj->full_scrn = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "fullScrn");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_media_node_data *
pptx_ct_p_tlmedia_node_video_get_c_media_node(const pptx_ct_p_tlmedia_node_video *const obj)
{
    return obj->c_media_node;
}

pptx_bool 
pptx_ct_p_tlmedia_node_video_get_full_scrn(const pptx_ct_p_tlmedia_node_video *const obj)
{
    return obj->full_scrn;
}

int32_t
pptx_ct_p_tlmedia_node_video_get_index(pptx_ct_p_tlmedia_node_video *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlmedia_node_video_free(pptx_ct_p_tlmedia_node_video *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_media_node_data_free(obj->c_media_node);
    free(obj);
}
#ifndef __PPTX_CT_P_TLMEDIA_NODE_VIDEO_H__
#define __PPTX_CT_P_TLMEDIA_NODE_VIDEO_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tlcommon_media_node_data_s pptx_ct_p_tlcommon_media_node_data;

typedef struct pptx_ct_p_tlmedia_node_video_s pptx_ct_p_tlmedia_node_video;
pptx_ct_p_tlmedia_node_video *pptx_ct_p_tlmedia_node_video_new(xmlNode *node);
void pptx_ct_p_tlmedia_node_video_free(pptx_ct_p_tlmedia_node_video *obj);
pptx_ct_p_tlcommon_media_node_data *pptx_ct_p_tlmedia_node_video_get_c_media_node(const pptx_ct_p_tlmedia_node_video *const obj);
pptx_bool pptx_ct_p_tlmedia_node_video_get_full_scrn(const pptx_ct_p_tlmedia_node_video *const obj);
int32_t pptx_ct_p_tlmedia_node_video_get_index(pptx_ct_p_tlmedia_node_video *obj);

#endif /* __PPTX_CT_P_TLMEDIA_NODE_VIDEO_H__ */

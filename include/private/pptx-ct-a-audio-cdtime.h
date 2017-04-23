#ifndef __PPTX_CT_A_AUDIO_CDTIME_H__
#define __PPTX_CT_A_AUDIO_CDTIME_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_audio_cdtime_s pptx_ct_a_audio_cdtime;
pptx_ct_a_audio_cdtime *pptx_ct_a_audio_cdtime_new(xmlNode *node);
void pptx_ct_a_audio_cdtime_free(pptx_ct_a_audio_cdtime *obj);
pptx_byte pptx_ct_a_audio_cdtime_get_track(const pptx_ct_a_audio_cdtime *const obj);
pptx_uint pptx_ct_a_audio_cdtime_get_time(const pptx_ct_a_audio_cdtime *const obj);
int32_t pptx_ct_a_audio_cdtime_get_index(pptx_ct_a_audio_cdtime *obj);

#endif /* __PPTX_CT_A_AUDIO_CDTIME_H__ */

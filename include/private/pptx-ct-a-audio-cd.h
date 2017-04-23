#ifndef __PPTX_CT_A_AUDIO_CD_H__
#define __PPTX_CT_A_AUDIO_CD_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_audio_cdtime_s pptx_ct_a_audio_cdtime;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_audio_cd_s pptx_ct_a_audio_cd;
pptx_ct_a_audio_cd *pptx_ct_a_audio_cd_new(xmlNode *node);
void pptx_ct_a_audio_cd_free(pptx_ct_a_audio_cd *obj);
pptx_ct_a_audio_cdtime *pptx_ct_a_audio_cd_get_st(const pptx_ct_a_audio_cd *const obj);
pptx_ct_a_audio_cdtime *pptx_ct_a_audio_cd_get_end(const pptx_ct_a_audio_cd *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_audio_cd_get_ext_lst(const pptx_ct_a_audio_cd *const obj);
int32_t pptx_ct_a_audio_cd_get_index(pptx_ct_a_audio_cd *obj);

#endif /* __PPTX_CT_A_AUDIO_CD_H__ */

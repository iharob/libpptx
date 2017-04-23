#ifndef __PPTX_CT_DGM_ANIM_ONE_H__
#define __PPTX_CT_DGM_ANIM_ONE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_anim_one_str_token_enum pptx_st_anim_one_str_token_enum;

typedef struct pptx_ct_dgm_anim_one_s pptx_ct_dgm_anim_one;
pptx_ct_dgm_anim_one *pptx_ct_dgm_anim_one_new(xmlNode *node);
void pptx_ct_dgm_anim_one_free(pptx_ct_dgm_anim_one *obj);
pptx_st_anim_one_str_token_enum pptx_ct_dgm_anim_one_get_val(const pptx_ct_dgm_anim_one *const obj);
int32_t pptx_ct_dgm_anim_one_get_index(pptx_ct_dgm_anim_one *obj);

#endif /* __PPTX_CT_DGM_ANIM_ONE_H__ */

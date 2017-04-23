#ifndef __PPTX_CT_DGM_ANIM_LVL_H__
#define __PPTX_CT_DGM_ANIM_LVL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_anim_lvl_str_token_enum pptx_st_anim_lvl_str_token_enum;

typedef struct pptx_ct_dgm_anim_lvl_s pptx_ct_dgm_anim_lvl;
pptx_ct_dgm_anim_lvl *pptx_ct_dgm_anim_lvl_new(xmlNode *node);
void pptx_ct_dgm_anim_lvl_free(pptx_ct_dgm_anim_lvl *obj);
pptx_st_anim_lvl_str_token_enum pptx_ct_dgm_anim_lvl_get_val(const pptx_ct_dgm_anim_lvl *const obj);
int32_t pptx_ct_dgm_anim_lvl_get_index(pptx_ct_dgm_anim_lvl *obj);

#endif /* __PPTX_CT_DGM_ANIM_LVL_H__ */

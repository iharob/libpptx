#ifndef __PPTX_CT_A_BLEND_EFFECT_H__
#define __PPTX_CT_A_BLEND_EFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_effect_container_s pptx_ct_a_effect_container;
typedef enum pptx_st_blend_mode_token_enum pptx_st_blend_mode_token_enum;

typedef struct pptx_ct_a_blend_effect_s pptx_ct_a_blend_effect;
pptx_ct_a_blend_effect *pptx_ct_a_blend_effect_new(xmlNode *node);
void pptx_ct_a_blend_effect_free(pptx_ct_a_blend_effect *obj);
pptx_ct_a_effect_container *pptx_ct_a_blend_effect_get_cont(const pptx_ct_a_blend_effect *const obj);
pptx_st_blend_mode_token_enum pptx_ct_a_blend_effect_get_blend(const pptx_ct_a_blend_effect *const obj);
int32_t pptx_ct_a_blend_effect_get_index(pptx_ct_a_blend_effect *obj);

#endif /* __PPTX_CT_A_BLEND_EFFECT_H__ */

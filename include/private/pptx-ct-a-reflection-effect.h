#ifndef __PPTX_CT_A_REFLECTION_EFFECT_H__
#define __PPTX_CT_A_REFLECTION_EFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_rect_alignment_token_enum pptx_st_rect_alignment_token_enum;

typedef struct pptx_ct_a_reflection_effect_s pptx_ct_a_reflection_effect;
pptx_ct_a_reflection_effect *pptx_ct_a_reflection_effect_new(xmlNode *node);
void pptx_ct_a_reflection_effect_free(pptx_ct_a_reflection_effect *obj);
pptx_long pptx_ct_a_reflection_effect_get_blur_rad(const pptx_ct_a_reflection_effect *const obj);
pptx_string pptx_ct_a_reflection_effect_get_st_a(const pptx_ct_a_reflection_effect *const obj);
pptx_string pptx_ct_a_reflection_effect_get_st_pos(const pptx_ct_a_reflection_effect *const obj);
pptx_string pptx_ct_a_reflection_effect_get_end_a(const pptx_ct_a_reflection_effect *const obj);
pptx_string pptx_ct_a_reflection_effect_get_end_pos(const pptx_ct_a_reflection_effect *const obj);
pptx_long pptx_ct_a_reflection_effect_get_dist(const pptx_ct_a_reflection_effect *const obj);
pptx_int pptx_ct_a_reflection_effect_get_dir(const pptx_ct_a_reflection_effect *const obj);
pptx_int pptx_ct_a_reflection_effect_get_fade_dir(const pptx_ct_a_reflection_effect *const obj);
pptx_string pptx_ct_a_reflection_effect_get_sx(const pptx_ct_a_reflection_effect *const obj);
pptx_string pptx_ct_a_reflection_effect_get_sy(const pptx_ct_a_reflection_effect *const obj);
pptx_int pptx_ct_a_reflection_effect_get_kx(const pptx_ct_a_reflection_effect *const obj);
pptx_int pptx_ct_a_reflection_effect_get_ky(const pptx_ct_a_reflection_effect *const obj);
pptx_st_rect_alignment_token_enum pptx_ct_a_reflection_effect_get_algn(const pptx_ct_a_reflection_effect *const obj);
pptx_bool pptx_ct_a_reflection_effect_get_rot_with_shape(const pptx_ct_a_reflection_effect *const obj);
int32_t pptx_ct_a_reflection_effect_get_index(pptx_ct_a_reflection_effect *obj);

#endif /* __PPTX_CT_A_REFLECTION_EFFECT_H__ */

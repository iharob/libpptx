#ifndef __PPTX_CT_A_EFFECT_LIST_H__
#define __PPTX_CT_A_EFFECT_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_blur_effect_s pptx_ct_a_blur_effect;
typedef struct pptx_ct_a_fill_overlay_effect_s pptx_ct_a_fill_overlay_effect;
typedef struct pptx_ct_a_glow_effect_s pptx_ct_a_glow_effect;
typedef struct pptx_ct_a_inner_shadow_effect_s pptx_ct_a_inner_shadow_effect;
typedef struct pptx_ct_a_outer_shadow_effect_s pptx_ct_a_outer_shadow_effect;
typedef struct pptx_ct_a_preset_shadow_effect_s pptx_ct_a_preset_shadow_effect;
typedef struct pptx_ct_a_reflection_effect_s pptx_ct_a_reflection_effect;
typedef struct pptx_ct_a_soft_edges_effect_s pptx_ct_a_soft_edges_effect;

typedef struct pptx_ct_a_effect_list_s pptx_ct_a_effect_list;
pptx_ct_a_effect_list *pptx_ct_a_effect_list_new(xmlNode *node);
void pptx_ct_a_effect_list_free(pptx_ct_a_effect_list *obj);
pptx_ct_a_blur_effect *pptx_ct_a_effect_list_get_blur(const pptx_ct_a_effect_list *const obj);
pptx_ct_a_fill_overlay_effect *pptx_ct_a_effect_list_get_fill_overlay(const pptx_ct_a_effect_list *const obj);
pptx_ct_a_glow_effect *pptx_ct_a_effect_list_get_glow(const pptx_ct_a_effect_list *const obj);
pptx_ct_a_inner_shadow_effect *pptx_ct_a_effect_list_get_inner_shdw(const pptx_ct_a_effect_list *const obj);
pptx_ct_a_outer_shadow_effect *pptx_ct_a_effect_list_get_outer_shdw(const pptx_ct_a_effect_list *const obj);
pptx_ct_a_preset_shadow_effect *pptx_ct_a_effect_list_get_prst_shdw(const pptx_ct_a_effect_list *const obj);
pptx_ct_a_reflection_effect *pptx_ct_a_effect_list_get_reflection(const pptx_ct_a_effect_list *const obj);
pptx_ct_a_soft_edges_effect *pptx_ct_a_effect_list_get_soft_edge(const pptx_ct_a_effect_list *const obj);
int32_t pptx_ct_a_effect_list_get_index(pptx_ct_a_effect_list *obj);

#endif /* __PPTX_CT_A_EFFECT_LIST_H__ */

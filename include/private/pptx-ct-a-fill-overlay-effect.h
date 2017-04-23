#ifndef __PPTX_CT_A_FILL_OVERLAY_EFFECT_H__
#define __PPTX_CT_A_FILL_OVERLAY_EFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_no_fill_properties_s pptx_ct_a_no_fill_properties;
typedef struct pptx_ct_a_solid_color_fill_properties_s pptx_ct_a_solid_color_fill_properties;
typedef struct pptx_ct_a_gradient_fill_properties_s pptx_ct_a_gradient_fill_properties;
typedef struct pptx_ct_a_blip_fill_properties_s pptx_ct_a_blip_fill_properties;
typedef struct pptx_ct_a_pattern_fill_properties_s pptx_ct_a_pattern_fill_properties;
typedef struct pptx_ct_a_group_fill_properties_s pptx_ct_a_group_fill_properties;
typedef enum pptx_st_blend_mode_token_enum pptx_st_blend_mode_token_enum;

typedef struct pptx_ct_a_fill_overlay_effect_s pptx_ct_a_fill_overlay_effect;
pptx_ct_a_fill_overlay_effect *pptx_ct_a_fill_overlay_effect_new(xmlNode *node);
void pptx_ct_a_fill_overlay_effect_free(pptx_ct_a_fill_overlay_effect *obj);
pptx_ct_a_no_fill_properties *pptx_ct_a_fill_overlay_effect_get_fill_properties_no_fill(const pptx_ct_a_fill_overlay_effect *const obj);
pptx_ct_a_solid_color_fill_properties *pptx_ct_a_fill_overlay_effect_get_fill_properties_solid_fill(const pptx_ct_a_fill_overlay_effect *const obj);
pptx_ct_a_gradient_fill_properties *pptx_ct_a_fill_overlay_effect_get_fill_properties_grad_fill(const pptx_ct_a_fill_overlay_effect *const obj);
pptx_ct_a_blip_fill_properties *pptx_ct_a_fill_overlay_effect_get_fill_properties_blip_fill(const pptx_ct_a_fill_overlay_effect *const obj);
pptx_ct_a_pattern_fill_properties *pptx_ct_a_fill_overlay_effect_get_fill_properties_patt_fill(const pptx_ct_a_fill_overlay_effect *const obj);
pptx_ct_a_group_fill_properties *pptx_ct_a_fill_overlay_effect_get_fill_properties_grp_fill(const pptx_ct_a_fill_overlay_effect *const obj);
pptx_st_blend_mode_token_enum pptx_ct_a_fill_overlay_effect_get_blend(const pptx_ct_a_fill_overlay_effect *const obj);
int32_t pptx_ct_a_fill_overlay_effect_get_index(pptx_ct_a_fill_overlay_effect *obj);

#endif /* __PPTX_CT_A_FILL_OVERLAY_EFFECT_H__ */

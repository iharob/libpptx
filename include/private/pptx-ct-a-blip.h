#ifndef __PPTX_CT_A_BLIP_H__
#define __PPTX_CT_A_BLIP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_alpha_bi_level_effect_s pptx_ct_a_alpha_bi_level_effect;
typedef struct pptx_ct_a_alpha_ceiling_effect_s pptx_ct_a_alpha_ceiling_effect;
typedef struct pptx_ct_a_alpha_floor_effect_s pptx_ct_a_alpha_floor_effect;
typedef struct pptx_ct_a_alpha_inverse_effect_s pptx_ct_a_alpha_inverse_effect;
typedef struct pptx_ct_a_alpha_modulate_effect_s pptx_ct_a_alpha_modulate_effect;
typedef struct pptx_ct_a_alpha_modulate_fixed_effect_s pptx_ct_a_alpha_modulate_fixed_effect;
typedef struct pptx_ct_a_alpha_replace_effect_s pptx_ct_a_alpha_replace_effect;
typedef struct pptx_ct_a_bi_level_effect_s pptx_ct_a_bi_level_effect;
typedef struct pptx_ct_a_blur_effect_s pptx_ct_a_blur_effect;
typedef struct pptx_ct_a_color_change_effect_s pptx_ct_a_color_change_effect;
typedef struct pptx_ct_a_color_replace_effect_s pptx_ct_a_color_replace_effect;
typedef struct pptx_ct_a_duotone_effect_s pptx_ct_a_duotone_effect;
typedef struct pptx_ct_a_fill_overlay_effect_s pptx_ct_a_fill_overlay_effect;
typedef struct pptx_ct_a_grayscale_effect_s pptx_ct_a_grayscale_effect;
typedef struct pptx_ct_a_hsleffect_s pptx_ct_a_hsleffect;
typedef struct pptx_ct_a_luminance_effect_s pptx_ct_a_luminance_effect;
typedef struct pptx_ct_a_tint_effect_s pptx_ct_a_tint_effect;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_blip_compression_token_enum pptx_st_blip_compression_token_enum;

typedef struct pptx_ct_a_blip_s pptx_ct_a_blip;
pptx_ct_a_blip *pptx_ct_a_blip_new(xmlNode *node);
void pptx_ct_a_blip_free(pptx_ct_a_blip *obj);
pptx_ct_a_alpha_bi_level_effect **pptx_ct_a_blip_get_alpha_bi_level(const pptx_ct_a_blip *const obj);
pptx_ct_a_alpha_ceiling_effect **pptx_ct_a_blip_get_alpha_ceiling(const pptx_ct_a_blip *const obj);
pptx_ct_a_alpha_floor_effect **pptx_ct_a_blip_get_alpha_floor(const pptx_ct_a_blip *const obj);
pptx_ct_a_alpha_inverse_effect **pptx_ct_a_blip_get_alpha_inv(const pptx_ct_a_blip *const obj);
pptx_ct_a_alpha_modulate_effect **pptx_ct_a_blip_get_alpha_mod(const pptx_ct_a_blip *const obj);
pptx_ct_a_alpha_modulate_fixed_effect **pptx_ct_a_blip_get_alpha_mod_fix(const pptx_ct_a_blip *const obj);
pptx_ct_a_alpha_replace_effect **pptx_ct_a_blip_get_alpha_repl(const pptx_ct_a_blip *const obj);
pptx_ct_a_bi_level_effect **pptx_ct_a_blip_get_bi_level(const pptx_ct_a_blip *const obj);
pptx_ct_a_blur_effect **pptx_ct_a_blip_get_blur(const pptx_ct_a_blip *const obj);
pptx_ct_a_color_change_effect **pptx_ct_a_blip_get_clr_change(const pptx_ct_a_blip *const obj);
pptx_ct_a_color_replace_effect **pptx_ct_a_blip_get_clr_repl(const pptx_ct_a_blip *const obj);
pptx_ct_a_duotone_effect **pptx_ct_a_blip_get_duotone(const pptx_ct_a_blip *const obj);
pptx_ct_a_fill_overlay_effect **pptx_ct_a_blip_get_fill_overlay(const pptx_ct_a_blip *const obj);
pptx_ct_a_grayscale_effect **pptx_ct_a_blip_get_grayscl(const pptx_ct_a_blip *const obj);
pptx_ct_a_hsleffect **pptx_ct_a_blip_get_hsl(const pptx_ct_a_blip *const obj);
pptx_ct_a_luminance_effect **pptx_ct_a_blip_get_lum(const pptx_ct_a_blip *const obj);
pptx_ct_a_tint_effect **pptx_ct_a_blip_get_tint(const pptx_ct_a_blip *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_blip_get_ext_lst(const pptx_ct_a_blip *const obj);
pptx_string pptx_ct_a_blip_get_embed(const pptx_ct_a_blip *const obj);
pptx_string pptx_ct_a_blip_get_link(const pptx_ct_a_blip *const obj);
pptx_st_blip_compression_token_enum pptx_ct_a_blip_get_cstate(const pptx_ct_a_blip *const obj);
int32_t pptx_ct_a_blip_get_index(pptx_ct_a_blip *obj);

#endif /* __PPTX_CT_A_BLIP_H__ */

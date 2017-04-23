#ifndef __PPTX_CT_A_FONT_REFERENCE_H__
#define __PPTX_CT_A_FONT_REFERENCE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_sc_rgb_color_s pptx_ct_a_sc_rgb_color;
typedef struct pptx_ct_a_srgb_color_s pptx_ct_a_srgb_color;
typedef struct pptx_ct_a_hsl_color_s pptx_ct_a_hsl_color;
typedef struct pptx_ct_a_system_color_s pptx_ct_a_system_color;
typedef struct pptx_ct_a_scheme_color_s pptx_ct_a_scheme_color;
typedef struct pptx_ct_a_preset_color_s pptx_ct_a_preset_color;
typedef enum pptx_st_font_collection_index_token_enum pptx_st_font_collection_index_token_enum;

typedef struct pptx_ct_a_font_reference_s pptx_ct_a_font_reference;
pptx_ct_a_font_reference *pptx_ct_a_font_reference_new(xmlNode *node);
void pptx_ct_a_font_reference_free(pptx_ct_a_font_reference *obj);
pptx_ct_a_sc_rgb_color *pptx_ct_a_font_reference_get_color_choice_scrgb_clr(const pptx_ct_a_font_reference *const obj);
pptx_ct_a_srgb_color *pptx_ct_a_font_reference_get_color_choice_srgb_clr(const pptx_ct_a_font_reference *const obj);
pptx_ct_a_hsl_color *pptx_ct_a_font_reference_get_color_choice_hsl_clr(const pptx_ct_a_font_reference *const obj);
pptx_ct_a_system_color *pptx_ct_a_font_reference_get_color_choice_sys_clr(const pptx_ct_a_font_reference *const obj);
pptx_ct_a_scheme_color *pptx_ct_a_font_reference_get_color_choice_scheme_clr(const pptx_ct_a_font_reference *const obj);
pptx_ct_a_preset_color *pptx_ct_a_font_reference_get_color_choice_prst_clr(const pptx_ct_a_font_reference *const obj);
pptx_st_font_collection_index_token_enum pptx_ct_a_font_reference_get_idx(const pptx_ct_a_font_reference *const obj);
int32_t pptx_ct_a_font_reference_get_index(pptx_ct_a_font_reference *obj);

#endif /* __PPTX_CT_A_FONT_REFERENCE_H__ */

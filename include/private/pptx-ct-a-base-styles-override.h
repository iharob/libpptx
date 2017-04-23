#ifndef __PPTX_CT_A_BASE_STYLES_OVERRIDE_H__
#define __PPTX_CT_A_BASE_STYLES_OVERRIDE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_color_scheme_s pptx_ct_a_color_scheme;
typedef struct pptx_ct_a_font_scheme_s pptx_ct_a_font_scheme;
typedef struct pptx_ct_a_style_matrix_s pptx_ct_a_style_matrix;

typedef struct pptx_ct_a_base_styles_override_s pptx_ct_a_base_styles_override;
pptx_ct_a_base_styles_override *pptx_ct_a_base_styles_override_new(xmlNode *node);
void pptx_ct_a_base_styles_override_free(pptx_ct_a_base_styles_override *obj);
pptx_ct_a_color_scheme *pptx_ct_a_base_styles_override_get_clr_scheme(const pptx_ct_a_base_styles_override *const obj);
pptx_ct_a_font_scheme *pptx_ct_a_base_styles_override_get_font_scheme(const pptx_ct_a_base_styles_override *const obj);
pptx_ct_a_style_matrix *pptx_ct_a_base_styles_override_get_fmt_scheme(const pptx_ct_a_base_styles_override *const obj);
int32_t pptx_ct_a_base_styles_override_get_index(pptx_ct_a_base_styles_override *obj);

#endif /* __PPTX_CT_A_BASE_STYLES_OVERRIDE_H__ */

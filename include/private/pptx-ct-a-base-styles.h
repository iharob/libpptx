#ifndef __PPTX_CT_A_BASE_STYLES_H__
#define __PPTX_CT_A_BASE_STYLES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_color_scheme_s pptx_ct_a_color_scheme;
typedef struct pptx_ct_a_font_scheme_s pptx_ct_a_font_scheme;
typedef struct pptx_ct_a_style_matrix_s pptx_ct_a_style_matrix;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_base_styles_s pptx_ct_a_base_styles;
pptx_ct_a_base_styles *pptx_ct_a_base_styles_new(xmlNode *node);
void pptx_ct_a_base_styles_free(pptx_ct_a_base_styles *obj);
pptx_ct_a_color_scheme *pptx_ct_a_base_styles_get_clr_scheme(const pptx_ct_a_base_styles *const obj);
pptx_ct_a_font_scheme *pptx_ct_a_base_styles_get_font_scheme(const pptx_ct_a_base_styles *const obj);
pptx_ct_a_style_matrix *pptx_ct_a_base_styles_get_fmt_scheme(const pptx_ct_a_base_styles *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_base_styles_get_ext_lst(const pptx_ct_a_base_styles *const obj);
int32_t pptx_ct_a_base_styles_get_index(pptx_ct_a_base_styles *obj);

#endif /* __PPTX_CT_A_BASE_STYLES_H__ */

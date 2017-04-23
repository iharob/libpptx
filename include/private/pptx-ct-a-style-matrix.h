#ifndef __PPTX_CT_A_STYLE_MATRIX_H__
#define __PPTX_CT_A_STYLE_MATRIX_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_fill_style_list_s pptx_ct_a_fill_style_list;
typedef struct pptx_ct_a_line_style_list_s pptx_ct_a_line_style_list;
typedef struct pptx_ct_a_effect_style_list_s pptx_ct_a_effect_style_list;
typedef struct pptx_ct_a_background_fill_style_list_s pptx_ct_a_background_fill_style_list;

typedef struct pptx_ct_a_style_matrix_s pptx_ct_a_style_matrix;
pptx_ct_a_style_matrix *pptx_ct_a_style_matrix_new(xmlNode *node);
void pptx_ct_a_style_matrix_free(pptx_ct_a_style_matrix *obj);
pptx_ct_a_fill_style_list *pptx_ct_a_style_matrix_get_fill_style_lst(const pptx_ct_a_style_matrix *const obj);
pptx_ct_a_line_style_list *pptx_ct_a_style_matrix_get_ln_style_lst(const pptx_ct_a_style_matrix *const obj);
pptx_ct_a_effect_style_list *pptx_ct_a_style_matrix_get_effect_style_lst(const pptx_ct_a_style_matrix *const obj);
pptx_ct_a_background_fill_style_list *pptx_ct_a_style_matrix_get_bg_fill_style_lst(const pptx_ct_a_style_matrix *const obj);
pptx_string pptx_ct_a_style_matrix_get_name(const pptx_ct_a_style_matrix *const obj);
int32_t pptx_ct_a_style_matrix_get_index(pptx_ct_a_style_matrix *obj);

#endif /* __PPTX_CT_A_STYLE_MATRIX_H__ */

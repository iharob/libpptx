#ifndef __PPTX_CT_A_SHAPE_STYLE_H__
#define __PPTX_CT_A_SHAPE_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_style_matrix_reference_s pptx_ct_a_style_matrix_reference;
typedef struct pptx_ct_a_font_reference_s pptx_ct_a_font_reference;

typedef struct pptx_ct_a_shape_style_s pptx_ct_a_shape_style;
pptx_ct_a_shape_style *pptx_ct_a_shape_style_new(xmlNode *node);
void pptx_ct_a_shape_style_free(pptx_ct_a_shape_style *obj);
pptx_ct_a_style_matrix_reference *pptx_ct_a_shape_style_get_ln_ref(const pptx_ct_a_shape_style *const obj);
pptx_ct_a_style_matrix_reference *pptx_ct_a_shape_style_get_fill_ref(const pptx_ct_a_shape_style *const obj);
pptx_ct_a_style_matrix_reference *pptx_ct_a_shape_style_get_effect_ref(const pptx_ct_a_shape_style *const obj);
pptx_ct_a_font_reference *pptx_ct_a_shape_style_get_font_ref(const pptx_ct_a_shape_style *const obj);
int32_t pptx_ct_a_shape_style_get_index(pptx_ct_a_shape_style *obj);

#endif /* __PPTX_CT_A_SHAPE_STYLE_H__ */

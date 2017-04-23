#ifndef __PPTX_CT_CDR_SHAPE_H__
#define __PPTX_CT_CDR_SHAPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_cdr_shape_non_visual_s pptx_ct_cdr_shape_non_visual;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_shape_style_s pptx_ct_a_shape_style;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;

typedef struct pptx_ct_cdr_shape_s pptx_ct_cdr_shape;
pptx_ct_cdr_shape *pptx_ct_cdr_shape_new(xmlNode *node);
void pptx_ct_cdr_shape_free(pptx_ct_cdr_shape *obj);
pptx_ct_cdr_shape_non_visual *pptx_ct_cdr_shape_get_nv_sp_pr(const pptx_ct_cdr_shape *const obj);
pptx_ct_a_shape_properties *pptx_ct_cdr_shape_get_sp_pr(const pptx_ct_cdr_shape *const obj);
pptx_ct_a_shape_style *pptx_ct_cdr_shape_get_style(const pptx_ct_cdr_shape *const obj);
pptx_ct_a_text_body *pptx_ct_cdr_shape_get_tx_body(const pptx_ct_cdr_shape *const obj);
pptx_string pptx_ct_cdr_shape_get_macro(const pptx_ct_cdr_shape *const obj);
pptx_string pptx_ct_cdr_shape_get_textlink(const pptx_ct_cdr_shape *const obj);
pptx_bool pptx_ct_cdr_shape_get_f_locks_text(const pptx_ct_cdr_shape *const obj);
pptx_bool pptx_ct_cdr_shape_get_f_published(const pptx_ct_cdr_shape *const obj);
int32_t pptx_ct_cdr_shape_get_index(pptx_ct_cdr_shape *obj);

#endif /* __PPTX_CT_CDR_SHAPE_H__ */

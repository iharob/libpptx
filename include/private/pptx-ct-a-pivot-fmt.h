#ifndef __PPTX_CT_A_PIVOT_FMT_H__
#define __PPTX_CT_A_PIVOT_FMT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_marker_s pptx_ct_a_marker;
typedef struct pptx_ct_a_dlbl_s pptx_ct_a_dlbl;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_pivot_fmt_s pptx_ct_a_pivot_fmt;
pptx_ct_a_pivot_fmt *pptx_ct_a_pivot_fmt_new(xmlNode *node);
void pptx_ct_a_pivot_fmt_free(pptx_ct_a_pivot_fmt *obj);
pptx_uint pptx_ct_a_pivot_fmt_get_idx(const pptx_ct_a_pivot_fmt *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_pivot_fmt_get_sp_pr(const pptx_ct_a_pivot_fmt *const obj);
pptx_ct_a_text_body *pptx_ct_a_pivot_fmt_get_tx_pr(const pptx_ct_a_pivot_fmt *const obj);
pptx_ct_a_marker *pptx_ct_a_pivot_fmt_get_marker(const pptx_ct_a_pivot_fmt *const obj);
pptx_ct_a_dlbl *pptx_ct_a_pivot_fmt_get_d_lbl(const pptx_ct_a_pivot_fmt *const obj);
pptx_ct_a_extension_list *pptx_ct_a_pivot_fmt_get_ext_lst(const pptx_ct_a_pivot_fmt *const obj);
int32_t pptx_ct_a_pivot_fmt_get_index(pptx_ct_a_pivot_fmt *obj);

#endif /* __PPTX_CT_A_PIVOT_FMT_H__ */

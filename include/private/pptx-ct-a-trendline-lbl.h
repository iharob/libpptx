#ifndef __PPTX_CT_A_TRENDLINE_LBL_H__
#define __PPTX_CT_A_TRENDLINE_LBL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_layout_s pptx_ct_a_layout;
typedef struct pptx_ct_a_tx_s pptx_ct_a_tx;
typedef struct pptx_ct_a_num_fmt_s pptx_ct_a_num_fmt;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_trendline_lbl_s pptx_ct_a_trendline_lbl;
pptx_ct_a_trendline_lbl *pptx_ct_a_trendline_lbl_new(xmlNode *node);
void pptx_ct_a_trendline_lbl_free(pptx_ct_a_trendline_lbl *obj);
pptx_ct_a_layout *pptx_ct_a_trendline_lbl_get_layout(const pptx_ct_a_trendline_lbl *const obj);
pptx_ct_a_tx *pptx_ct_a_trendline_lbl_get_tx(const pptx_ct_a_trendline_lbl *const obj);
pptx_ct_a_num_fmt *pptx_ct_a_trendline_lbl_get_num_fmt(const pptx_ct_a_trendline_lbl *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_trendline_lbl_get_sp_pr(const pptx_ct_a_trendline_lbl *const obj);
pptx_ct_a_text_body *pptx_ct_a_trendline_lbl_get_tx_pr(const pptx_ct_a_trendline_lbl *const obj);
pptx_ct_a_extension_list *pptx_ct_a_trendline_lbl_get_ext_lst(const pptx_ct_a_trendline_lbl *const obj);
int32_t pptx_ct_a_trendline_lbl_get_index(pptx_ct_a_trendline_lbl *obj);

#endif /* __PPTX_CT_A_TRENDLINE_LBL_H__ */

#ifndef __PPTX_CT_A_DLBLS_H__
#define __PPTX_CT_A_DLBLS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_dlbl_s pptx_ct_a_dlbl;
typedef struct pptx_ct_a_num_fmt_s pptx_ct_a_num_fmt;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_dlbl_pos_s pptx_ct_a_dlbl_pos;
typedef struct pptx_ct_a_chart_lines_s pptx_ct_a_chart_lines;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
pptx_ct_a_dlbls *pptx_ct_a_dlbls_new(xmlNode *node);
void pptx_ct_a_dlbls_free(pptx_ct_a_dlbls *obj);
pptx_ct_a_dlbl **pptx_ct_a_dlbls_get_d_lbl(const pptx_ct_a_dlbls *const obj);
pptx_bool pptx_ct_a_dlbls_get_delete(const pptx_ct_a_dlbls *const obj);
pptx_ct_a_num_fmt *pptx_ct_a_dlbls_get_dlbl_shared_num_fmt(const pptx_ct_a_dlbls *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_dlbls_get_dlbl_shared_sp_pr(const pptx_ct_a_dlbls *const obj);
pptx_ct_a_text_body *pptx_ct_a_dlbls_get_dlbl_shared_tx_pr(const pptx_ct_a_dlbls *const obj);
pptx_ct_a_dlbl_pos *pptx_ct_a_dlbls_get_dlbl_shared_d_lbl_pos(const pptx_ct_a_dlbls *const obj);
pptx_bool pptx_ct_a_dlbls_get_dlbl_shared_show_legend_key(const pptx_ct_a_dlbls *const obj);
pptx_bool pptx_ct_a_dlbls_get_dlbl_shared_show_val(const pptx_ct_a_dlbls *const obj);
pptx_bool pptx_ct_a_dlbls_get_dlbl_shared_show_cat_name(const pptx_ct_a_dlbls *const obj);
pptx_bool pptx_ct_a_dlbls_get_dlbl_shared_show_ser_name(const pptx_ct_a_dlbls *const obj);
pptx_bool pptx_ct_a_dlbls_get_dlbl_shared_show_percent(const pptx_ct_a_dlbls *const obj);
pptx_bool pptx_ct_a_dlbls_get_dlbl_shared_show_bubble_size(const pptx_ct_a_dlbls *const obj);
pptx_string pptx_ct_a_dlbls_get_dlbl_shared_separator(const pptx_ct_a_dlbls *const obj);
pptx_bool pptx_ct_a_dlbls_get_group_dlbls_show_leader_lines(const pptx_ct_a_dlbls *const obj);
pptx_ct_a_chart_lines *pptx_ct_a_dlbls_get_group_dlbls_leader_lines(const pptx_ct_a_dlbls *const obj);
pptx_ct_a_extension_list *pptx_ct_a_dlbls_get_ext_lst(const pptx_ct_a_dlbls *const obj);
int32_t pptx_ct_a_dlbls_get_index(pptx_ct_a_dlbls *obj);

#endif /* __PPTX_CT_A_DLBLS_H__ */

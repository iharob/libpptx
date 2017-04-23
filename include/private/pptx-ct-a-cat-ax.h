#ifndef __PPTX_CT_A_CAT_AX_H__
#define __PPTX_CT_A_CAT_AX_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_scaling_s pptx_ct_a_scaling;
typedef struct pptx_ct_a_ax_pos_s pptx_ct_a_ax_pos;
typedef struct pptx_ct_a_chart_lines_s pptx_ct_a_chart_lines;
typedef struct pptx_ct_a_title_s pptx_ct_a_title;
typedef struct pptx_ct_a_num_fmt_s pptx_ct_a_num_fmt;
typedef struct pptx_ct_a_tick_mark_s pptx_ct_a_tick_mark;
typedef struct pptx_ct_a_tick_lbl_pos_s pptx_ct_a_tick_lbl_pos;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_crosses_s pptx_ct_a_crosses;
typedef struct pptx_ct_a_double_s pptx_ct_a_double;
typedef struct pptx_ct_a_lbl_algn_s pptx_ct_a_lbl_algn;
typedef struct pptx_ct_a_lbl_offset_s pptx_ct_a_lbl_offset;
typedef struct pptx_ct_a_skip_s pptx_ct_a_skip;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_cat_ax_s pptx_ct_a_cat_ax;
pptx_ct_a_cat_ax *pptx_ct_a_cat_ax_new(xmlNode *node);
void pptx_ct_a_cat_ax_free(pptx_ct_a_cat_ax *obj);
pptx_uint pptx_ct_a_cat_ax_get_ax_shared_ax_id(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_scaling *pptx_ct_a_cat_ax_get_ax_shared_scaling(const pptx_ct_a_cat_ax *const obj);
pptx_bool pptx_ct_a_cat_ax_get_ax_shared_delete(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_ax_pos *pptx_ct_a_cat_ax_get_ax_shared_ax_pos(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_chart_lines *pptx_ct_a_cat_ax_get_ax_shared_major_gridlines(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_chart_lines *pptx_ct_a_cat_ax_get_ax_shared_minor_gridlines(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_title *pptx_ct_a_cat_ax_get_ax_shared_title(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_num_fmt *pptx_ct_a_cat_ax_get_ax_shared_num_fmt(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_tick_mark *pptx_ct_a_cat_ax_get_ax_shared_major_tick_mark(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_tick_mark *pptx_ct_a_cat_ax_get_ax_shared_minor_tick_mark(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_tick_lbl_pos *pptx_ct_a_cat_ax_get_ax_shared_tick_lbl_pos(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_cat_ax_get_ax_shared_sp_pr(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_text_body *pptx_ct_a_cat_ax_get_ax_shared_tx_pr(const pptx_ct_a_cat_ax *const obj);
pptx_uint pptx_ct_a_cat_ax_get_ax_shared_cross_ax(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_crosses *pptx_ct_a_cat_ax_get_crosses(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_double *pptx_ct_a_cat_ax_get_crosses_at(const pptx_ct_a_cat_ax *const obj);
pptx_bool pptx_ct_a_cat_ax_get__auto(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_lbl_algn *pptx_ct_a_cat_ax_get_lbl_algn(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_lbl_offset *pptx_ct_a_cat_ax_get_lbl_offset(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_skip *pptx_ct_a_cat_ax_get_tick_lbl_skip(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_skip *pptx_ct_a_cat_ax_get_tick_mark_skip(const pptx_ct_a_cat_ax *const obj);
pptx_bool pptx_ct_a_cat_ax_get_no_multi_lvl_lbl(const pptx_ct_a_cat_ax *const obj);
pptx_ct_a_extension_list *pptx_ct_a_cat_ax_get_ext_lst(const pptx_ct_a_cat_ax *const obj);
int32_t pptx_ct_a_cat_ax_get_index(pptx_ct_a_cat_ax *obj);

#endif /* __PPTX_CT_A_CAT_AX_H__ */

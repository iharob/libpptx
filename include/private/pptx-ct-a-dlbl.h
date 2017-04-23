#ifndef __PPTX_CT_A_DLBL_H__
#define __PPTX_CT_A_DLBL_H__

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
typedef struct pptx_ct_a_dlbl_pos_s pptx_ct_a_dlbl_pos;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_dlbl_s pptx_ct_a_dlbl;
pptx_ct_a_dlbl *pptx_ct_a_dlbl_new(xmlNode *node);
void pptx_ct_a_dlbl_free(pptx_ct_a_dlbl *obj);
pptx_uint pptx_ct_a_dlbl_get_idx(const pptx_ct_a_dlbl *const obj);
pptx_bool pptx_ct_a_dlbl_get_delete(const pptx_ct_a_dlbl *const obj);
pptx_ct_a_layout *pptx_ct_a_dlbl_get_group_dlbl_layout(const pptx_ct_a_dlbl *const obj);
pptx_ct_a_tx *pptx_ct_a_dlbl_get_group_dlbl_tx(const pptx_ct_a_dlbl *const obj);
pptx_ct_a_num_fmt *pptx_ct_a_dlbl_get_dlbl_shared_num_fmt(const pptx_ct_a_dlbl *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_dlbl_get_dlbl_shared_sp_pr(const pptx_ct_a_dlbl *const obj);
pptx_ct_a_text_body *pptx_ct_a_dlbl_get_dlbl_shared_tx_pr(const pptx_ct_a_dlbl *const obj);
pptx_ct_a_dlbl_pos *pptx_ct_a_dlbl_get_dlbl_shared_d_lbl_pos(const pptx_ct_a_dlbl *const obj);
pptx_bool pptx_ct_a_dlbl_get_dlbl_shared_show_legend_key(const pptx_ct_a_dlbl *const obj);
pptx_bool pptx_ct_a_dlbl_get_dlbl_shared_show_val(const pptx_ct_a_dlbl *const obj);
pptx_bool pptx_ct_a_dlbl_get_dlbl_shared_show_cat_name(const pptx_ct_a_dlbl *const obj);
pptx_bool pptx_ct_a_dlbl_get_dlbl_shared_show_ser_name(const pptx_ct_a_dlbl *const obj);
pptx_bool pptx_ct_a_dlbl_get_dlbl_shared_show_percent(const pptx_ct_a_dlbl *const obj);
pptx_bool pptx_ct_a_dlbl_get_dlbl_shared_show_bubble_size(const pptx_ct_a_dlbl *const obj);
pptx_string pptx_ct_a_dlbl_get_dlbl_shared_separator(const pptx_ct_a_dlbl *const obj);
pptx_ct_a_extension_list *pptx_ct_a_dlbl_get_ext_lst(const pptx_ct_a_dlbl *const obj);
int32_t pptx_ct_a_dlbl_get_index(pptx_ct_a_dlbl *obj);

#endif /* __PPTX_CT_A_DLBL_H__ */

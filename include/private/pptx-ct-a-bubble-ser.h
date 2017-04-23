#ifndef __PPTX_CT_A_BUBBLE_SER_H__
#define __PPTX_CT_A_BUBBLE_SER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_ser_tx_s pptx_ct_a_ser_tx;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_dpt_s pptx_ct_a_dpt;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_trendline_s pptx_ct_a_trendline;
typedef struct pptx_ct_a_err_bars_s pptx_ct_a_err_bars;
typedef struct pptx_ct_a_ax_data_source_s pptx_ct_a_ax_data_source;
typedef struct pptx_ct_a_num_data_source_s pptx_ct_a_num_data_source;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_bubble_ser_s pptx_ct_a_bubble_ser;
pptx_ct_a_bubble_ser *pptx_ct_a_bubble_ser_new(xmlNode *node);
void pptx_ct_a_bubble_ser_free(pptx_ct_a_bubble_ser *obj);
pptx_uint pptx_ct_a_bubble_ser_get_ser_shared_idx(const pptx_ct_a_bubble_ser *const obj);
pptx_uint pptx_ct_a_bubble_ser_get_ser_shared_order(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_ser_tx *pptx_ct_a_bubble_ser_get_ser_shared_tx(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_bubble_ser_get_ser_shared_sp_pr(const pptx_ct_a_bubble_ser *const obj);
pptx_bool pptx_ct_a_bubble_ser_get_invert_if_negative(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_dpt **pptx_ct_a_bubble_ser_get_d_pt(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_dlbls *pptx_ct_a_bubble_ser_get_d_lbls(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_trendline **pptx_ct_a_bubble_ser_get_trendline(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_err_bars **pptx_ct_a_bubble_ser_get_err_bars(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_ax_data_source *pptx_ct_a_bubble_ser_get_x_val(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_num_data_source *pptx_ct_a_bubble_ser_get_y_val(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_num_data_source *pptx_ct_a_bubble_ser_get_bubble_size(const pptx_ct_a_bubble_ser *const obj);
pptx_bool pptx_ct_a_bubble_ser_get_bubble_3d(const pptx_ct_a_bubble_ser *const obj);
pptx_ct_a_extension_list *pptx_ct_a_bubble_ser_get_ext_lst(const pptx_ct_a_bubble_ser *const obj);
int32_t pptx_ct_a_bubble_ser_get_index(pptx_ct_a_bubble_ser *obj);

#endif /* __PPTX_CT_A_BUBBLE_SER_H__ */

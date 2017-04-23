#ifndef __PPTX_CT_A_RADAR_SER_H__
#define __PPTX_CT_A_RADAR_SER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_ser_tx_s pptx_ct_a_ser_tx;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_marker_s pptx_ct_a_marker;
typedef struct pptx_ct_a_dpt_s pptx_ct_a_dpt;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_ax_data_source_s pptx_ct_a_ax_data_source;
typedef struct pptx_ct_a_num_data_source_s pptx_ct_a_num_data_source;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_radar_ser_s pptx_ct_a_radar_ser;
pptx_ct_a_radar_ser *pptx_ct_a_radar_ser_new(xmlNode *node);
void pptx_ct_a_radar_ser_free(pptx_ct_a_radar_ser *obj);
pptx_uint pptx_ct_a_radar_ser_get_ser_shared_idx(const pptx_ct_a_radar_ser *const obj);
pptx_uint pptx_ct_a_radar_ser_get_ser_shared_order(const pptx_ct_a_radar_ser *const obj);
pptx_ct_a_ser_tx *pptx_ct_a_radar_ser_get_ser_shared_tx(const pptx_ct_a_radar_ser *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_radar_ser_get_ser_shared_sp_pr(const pptx_ct_a_radar_ser *const obj);
pptx_ct_a_marker *pptx_ct_a_radar_ser_get_marker(const pptx_ct_a_radar_ser *const obj);
pptx_ct_a_dpt **pptx_ct_a_radar_ser_get_d_pt(const pptx_ct_a_radar_ser *const obj);
pptx_ct_a_dlbls *pptx_ct_a_radar_ser_get_d_lbls(const pptx_ct_a_radar_ser *const obj);
pptx_ct_a_ax_data_source *pptx_ct_a_radar_ser_get_cat(const pptx_ct_a_radar_ser *const obj);
pptx_ct_a_num_data_source *pptx_ct_a_radar_ser_get_val(const pptx_ct_a_radar_ser *const obj);
pptx_ct_a_extension_list *pptx_ct_a_radar_ser_get_ext_lst(const pptx_ct_a_radar_ser *const obj);
int32_t pptx_ct_a_radar_ser_get_index(pptx_ct_a_radar_ser *obj);

#endif /* __PPTX_CT_A_RADAR_SER_H__ */

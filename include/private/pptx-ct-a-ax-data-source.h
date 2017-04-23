#ifndef __PPTX_CT_A_AX_DATA_SOURCE_H__
#define __PPTX_CT_A_AX_DATA_SOURCE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_multi_lvl_str_ref_s pptx_ct_a_multi_lvl_str_ref;
typedef struct pptx_ct_a_num_ref_s pptx_ct_a_num_ref;
typedef struct pptx_ct_a_num_data_s pptx_ct_a_num_data;
typedef struct pptx_ct_a_str_ref_s pptx_ct_a_str_ref;
typedef struct pptx_ct_a_str_data_s pptx_ct_a_str_data;

typedef struct pptx_ct_a_ax_data_source_s pptx_ct_a_ax_data_source;
pptx_ct_a_ax_data_source *pptx_ct_a_ax_data_source_new(xmlNode *node);
void pptx_ct_a_ax_data_source_free(pptx_ct_a_ax_data_source *obj);
pptx_ct_a_multi_lvl_str_ref *pptx_ct_a_ax_data_source_get_multi_lvl_str_ref(const pptx_ct_a_ax_data_source *const obj);
pptx_ct_a_num_ref *pptx_ct_a_ax_data_source_get_num_ref(const pptx_ct_a_ax_data_source *const obj);
pptx_ct_a_num_data *pptx_ct_a_ax_data_source_get_num_lit(const pptx_ct_a_ax_data_source *const obj);
pptx_ct_a_str_ref *pptx_ct_a_ax_data_source_get_str_ref(const pptx_ct_a_ax_data_source *const obj);
pptx_ct_a_str_data *pptx_ct_a_ax_data_source_get_str_lit(const pptx_ct_a_ax_data_source *const obj);
int32_t pptx_ct_a_ax_data_source_get_index(pptx_ct_a_ax_data_source *obj);

#endif /* __PPTX_CT_A_AX_DATA_SOURCE_H__ */

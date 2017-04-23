#ifndef __PPTX_CT_A_NUM_DATA_H__
#define __PPTX_CT_A_NUM_DATA_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_num_val_s pptx_ct_a_num_val;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_num_data_s pptx_ct_a_num_data;
pptx_ct_a_num_data *pptx_ct_a_num_data_new(xmlNode *node);
void pptx_ct_a_num_data_free(pptx_ct_a_num_data *obj);
pptx_string pptx_ct_a_num_data_get_format_code(const pptx_ct_a_num_data *const obj);
pptx_uint pptx_ct_a_num_data_get_pt_count(const pptx_ct_a_num_data *const obj);
pptx_ct_a_num_val **pptx_ct_a_num_data_get_pt(const pptx_ct_a_num_data *const obj);
pptx_ct_a_extension_list *pptx_ct_a_num_data_get_ext_lst(const pptx_ct_a_num_data *const obj);
int32_t pptx_ct_a_num_data_get_index(pptx_ct_a_num_data *obj);

#endif /* __PPTX_CT_A_NUM_DATA_H__ */

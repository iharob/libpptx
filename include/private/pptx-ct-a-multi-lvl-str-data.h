#ifndef __PPTX_CT_A_MULTI_LVL_STR_DATA_H__
#define __PPTX_CT_A_MULTI_LVL_STR_DATA_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_lvl_s pptx_ct_a_lvl;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_multi_lvl_str_data_s pptx_ct_a_multi_lvl_str_data;
pptx_ct_a_multi_lvl_str_data *pptx_ct_a_multi_lvl_str_data_new(xmlNode *node);
void pptx_ct_a_multi_lvl_str_data_free(pptx_ct_a_multi_lvl_str_data *obj);
pptx_uint pptx_ct_a_multi_lvl_str_data_get_pt_count(const pptx_ct_a_multi_lvl_str_data *const obj);
pptx_ct_a_lvl **pptx_ct_a_multi_lvl_str_data_get_lvl(const pptx_ct_a_multi_lvl_str_data *const obj);
pptx_ct_a_extension_list *pptx_ct_a_multi_lvl_str_data_get_ext_lst(const pptx_ct_a_multi_lvl_str_data *const obj);
int32_t pptx_ct_a_multi_lvl_str_data_get_index(pptx_ct_a_multi_lvl_str_data *obj);

#endif /* __PPTX_CT_A_MULTI_LVL_STR_DATA_H__ */

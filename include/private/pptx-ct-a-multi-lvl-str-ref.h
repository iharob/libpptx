#ifndef __PPTX_CT_A_MULTI_LVL_STR_REF_H__
#define __PPTX_CT_A_MULTI_LVL_STR_REF_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_multi_lvl_str_data_s pptx_ct_a_multi_lvl_str_data;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_multi_lvl_str_ref_s pptx_ct_a_multi_lvl_str_ref;
pptx_ct_a_multi_lvl_str_ref *pptx_ct_a_multi_lvl_str_ref_new(xmlNode *node);
void pptx_ct_a_multi_lvl_str_ref_free(pptx_ct_a_multi_lvl_str_ref *obj);
pptx_string pptx_ct_a_multi_lvl_str_ref_get_f(const pptx_ct_a_multi_lvl_str_ref *const obj);
pptx_ct_a_multi_lvl_str_data *pptx_ct_a_multi_lvl_str_ref_get_multi_lvl_str_cache(const pptx_ct_a_multi_lvl_str_ref *const obj);
pptx_ct_a_extension_list *pptx_ct_a_multi_lvl_str_ref_get_ext_lst(const pptx_ct_a_multi_lvl_str_ref *const obj);
int32_t pptx_ct_a_multi_lvl_str_ref_get_index(pptx_ct_a_multi_lvl_str_ref *obj);

#endif /* __PPTX_CT_A_MULTI_LVL_STR_REF_H__ */

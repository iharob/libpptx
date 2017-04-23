#ifndef __PPTX_CT_P_COMMON_SLIDE_DATA_H__
#define __PPTX_CT_P_COMMON_SLIDE_DATA_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_background_s pptx_ct_p_background;
typedef struct pptx_ct_p_group_shape_s pptx_ct_p_group_shape;
typedef struct pptx_ct_p_customer_data_list_s pptx_ct_p_customer_data_list;
typedef struct pptx_ct_p_control_list_s pptx_ct_p_control_list;
typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;

typedef struct pptx_ct_p_common_slide_data_s pptx_ct_p_common_slide_data;
pptx_ct_p_common_slide_data *pptx_ct_p_common_slide_data_new(xmlNode *node);
void pptx_ct_p_common_slide_data_free(pptx_ct_p_common_slide_data *obj);
pptx_ct_p_background *pptx_ct_p_common_slide_data_get_bg(const pptx_ct_p_common_slide_data *const obj);
pptx_ct_p_group_shape *pptx_ct_p_common_slide_data_get_sp_tree(const pptx_ct_p_common_slide_data *const obj);
pptx_ct_p_customer_data_list *pptx_ct_p_common_slide_data_get_cust_data_lst(const pptx_ct_p_common_slide_data *const obj);
pptx_ct_p_control_list *pptx_ct_p_common_slide_data_get_controls(const pptx_ct_p_common_slide_data *const obj);
pptx_ct_p_extension_list *pptx_ct_p_common_slide_data_get_ext_lst(const pptx_ct_p_common_slide_data *const obj);
pptx_string pptx_ct_p_common_slide_data_get_name(const pptx_ct_p_common_slide_data *const obj);
int32_t pptx_ct_p_common_slide_data_get_index(pptx_ct_p_common_slide_data *obj);

#endif /* __PPTX_CT_P_COMMON_SLIDE_DATA_H__ */

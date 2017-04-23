#ifndef __PPTX_CT_P_CUSTOMER_DATA_LIST_H__
#define __PPTX_CT_P_CUSTOMER_DATA_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_customer_data_s pptx_ct_p_customer_data;
typedef struct pptx_ct_p_tags_data_s pptx_ct_p_tags_data;

typedef struct pptx_ct_p_customer_data_list_s pptx_ct_p_customer_data_list;
pptx_ct_p_customer_data_list *pptx_ct_p_customer_data_list_new(xmlNode *node);
void pptx_ct_p_customer_data_list_free(pptx_ct_p_customer_data_list *obj);
pptx_ct_p_customer_data **pptx_ct_p_customer_data_list_get_cust_data(const pptx_ct_p_customer_data_list *const obj);
pptx_ct_p_tags_data *pptx_ct_p_customer_data_list_get_tags(const pptx_ct_p_customer_data_list *const obj);
int32_t pptx_ct_p_customer_data_list_get_index(pptx_ct_p_customer_data_list *obj);

#endif /* __PPTX_CT_P_CUSTOMER_DATA_LIST_H__ */

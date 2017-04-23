#ifndef __PPTX_CT_A_CUST_SPLIT_H__
#define __PPTX_CT_A_CUST_SPLIT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_cust_split_s pptx_ct_a_cust_split;
pptx_ct_a_cust_split *pptx_ct_a_cust_split_new(xmlNode *node);
void pptx_ct_a_cust_split_free(pptx_ct_a_cust_split *obj);
int32_t pptx_ct_a_cust_split_get_index(pptx_ct_a_cust_split *obj);

#endif /* __PPTX_CT_A_CUST_SPLIT_H__ */

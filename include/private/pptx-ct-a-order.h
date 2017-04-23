#ifndef __PPTX_CT_A_ORDER_H__
#define __PPTX_CT_A_ORDER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_order_s pptx_ct_a_order;
pptx_ct_a_order *pptx_ct_a_order_new(xmlNode *node);
void pptx_ct_a_order_free(pptx_ct_a_order *obj);
pptx_byte pptx_ct_a_order_get_val(const pptx_ct_a_order *const obj);
int32_t pptx_ct_a_order_get_index(pptx_ct_a_order *obj);

#endif /* __PPTX_CT_A_ORDER_H__ */

#ifndef __PPTX_CT_A_SER_TX_H__
#define __PPTX_CT_A_SER_TX_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_str_ref_s pptx_ct_a_str_ref;

typedef struct pptx_ct_a_ser_tx_s pptx_ct_a_ser_tx;
pptx_ct_a_ser_tx *pptx_ct_a_ser_tx_new(xmlNode *node);
void pptx_ct_a_ser_tx_free(pptx_ct_a_ser_tx *obj);
pptx_ct_a_str_ref *pptx_ct_a_ser_tx_get_str_ref(const pptx_ct_a_ser_tx *const obj);
pptx_string pptx_ct_a_ser_tx_get_v(const pptx_ct_a_ser_tx *const obj);
int32_t pptx_ct_a_ser_tx_get_index(pptx_ct_a_ser_tx *obj);

#endif /* __PPTX_CT_A_SER_TX_H__ */

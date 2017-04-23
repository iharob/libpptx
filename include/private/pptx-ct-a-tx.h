#ifndef __PPTX_CT_A_TX_H__
#define __PPTX_CT_A_TX_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_str_ref_s pptx_ct_a_str_ref;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;

typedef struct pptx_ct_a_tx_s pptx_ct_a_tx;
pptx_ct_a_tx *pptx_ct_a_tx_new(xmlNode *node);
void pptx_ct_a_tx_free(pptx_ct_a_tx *obj);
pptx_ct_a_str_ref *pptx_ct_a_tx_get_str_ref(const pptx_ct_a_tx *const obj);
pptx_ct_a_text_body *pptx_ct_a_tx_get_rich(const pptx_ct_a_tx *const obj);
int32_t pptx_ct_a_tx_get_index(pptx_ct_a_tx *obj);

#endif /* __PPTX_CT_A_TX_H__ */

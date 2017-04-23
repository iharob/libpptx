#ifndef __PPTX_CT_A_GAP_AMOUNT_H__
#define __PPTX_CT_A_GAP_AMOUNT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_gap_amount_s pptx_ct_a_gap_amount;
pptx_ct_a_gap_amount *pptx_ct_a_gap_amount_new(xmlNode *node);
void pptx_ct_a_gap_amount_free(pptx_ct_a_gap_amount *obj);
pptx_string pptx_ct_a_gap_amount_get_val(const pptx_ct_a_gap_amount *const obj);
int32_t pptx_ct_a_gap_amount_get_index(pptx_ct_a_gap_amount *obj);

#endif /* __PPTX_CT_A_GAP_AMOUNT_H__ */

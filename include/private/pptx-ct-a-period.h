#ifndef __PPTX_CT_A_PERIOD_H__
#define __PPTX_CT_A_PERIOD_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_period_s pptx_ct_a_period;
pptx_ct_a_period *pptx_ct_a_period_new(xmlNode *node);
void pptx_ct_a_period_free(pptx_ct_a_period *obj);
pptx_uint pptx_ct_a_period_get_val(const pptx_ct_a_period *const obj);
int32_t pptx_ct_a_period_get_index(pptx_ct_a_period *obj);

#endif /* __PPTX_CT_A_PERIOD_H__ */

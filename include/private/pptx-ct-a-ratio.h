#ifndef __PPTX_CT_A_RATIO_H__
#define __PPTX_CT_A_RATIO_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_ratio_s pptx_ct_a_ratio;
pptx_ct_a_ratio *pptx_ct_a_ratio_new(xmlNode *node);
void pptx_ct_a_ratio_free(pptx_ct_a_ratio *obj);
pptx_long pptx_ct_a_ratio_get_n(const pptx_ct_a_ratio *const obj);
pptx_long pptx_ct_a_ratio_get_d(const pptx_ct_a_ratio *const obj);
int32_t pptx_ct_a_ratio_get_index(pptx_ct_a_ratio *obj);

#endif /* __PPTX_CT_A_RATIO_H__ */

#ifndef __PPTX_CT_A_POSITIVE_PERCENTAGE_H__
#define __PPTX_CT_A_POSITIVE_PERCENTAGE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_positive_percentage_s pptx_ct_a_positive_percentage;
pptx_ct_a_positive_percentage *pptx_ct_a_positive_percentage_new(xmlNode *node);
void pptx_ct_a_positive_percentage_free(pptx_ct_a_positive_percentage *obj);
pptx_string pptx_ct_a_positive_percentage_get_val(const pptx_ct_a_positive_percentage *const obj);
int32_t pptx_ct_a_positive_percentage_get_index(pptx_ct_a_positive_percentage *obj);

#endif /* __PPTX_CT_A_POSITIVE_PERCENTAGE_H__ */

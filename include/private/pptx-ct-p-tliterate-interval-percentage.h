#ifndef __PPTX_CT_P_TLITERATE_INTERVAL_PERCENTAGE_H__
#define __PPTX_CT_P_TLITERATE_INTERVAL_PERCENTAGE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_tliterate_interval_percentage_s pptx_ct_p_tliterate_interval_percentage;
pptx_ct_p_tliterate_interval_percentage *pptx_ct_p_tliterate_interval_percentage_new(xmlNode *node);
void pptx_ct_p_tliterate_interval_percentage_free(pptx_ct_p_tliterate_interval_percentage *obj);
pptx_string pptx_ct_p_tliterate_interval_percentage_get_val(const pptx_ct_p_tliterate_interval_percentage *const obj);
int32_t pptx_ct_p_tliterate_interval_percentage_get_index(pptx_ct_p_tliterate_interval_percentage *obj);

#endif /* __PPTX_CT_P_TLITERATE_INTERVAL_PERCENTAGE_H__ */

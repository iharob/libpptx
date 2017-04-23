#ifndef __PPTX_CT_P_TLITERATE_INTERVAL_TIME_H__
#define __PPTX_CT_P_TLITERATE_INTERVAL_TIME_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltime_indefinite_token_enum pptx_st_tltime_indefinite_token_enum;

typedef struct pptx_ct_p_tliterate_interval_time_s pptx_ct_p_tliterate_interval_time;
pptx_ct_p_tliterate_interval_time *pptx_ct_p_tliterate_interval_time_new(xmlNode *node);
void pptx_ct_p_tliterate_interval_time_free(pptx_ct_p_tliterate_interval_time *obj);
pptx_st_tltime_indefinite_token_enum pptx_ct_p_tliterate_interval_time_get_val(const pptx_ct_p_tliterate_interval_time *const obj);
int32_t pptx_ct_p_tliterate_interval_time_get_index(pptx_ct_p_tliterate_interval_time *obj);

#endif /* __PPTX_CT_P_TLITERATE_INTERVAL_TIME_H__ */

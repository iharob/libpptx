#ifndef __PPTX_CT_P_TLITERATE_DATA_H__
#define __PPTX_CT_P_TLITERATE_DATA_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tliterate_interval_time_s pptx_ct_p_tliterate_interval_time;
typedef struct pptx_ct_p_tliterate_interval_percentage_s pptx_ct_p_tliterate_interval_percentage;
typedef enum pptx_st_iterate_type_token_enum pptx_st_iterate_type_token_enum;

typedef struct pptx_ct_p_tliterate_data_s pptx_ct_p_tliterate_data;
pptx_ct_p_tliterate_data *pptx_ct_p_tliterate_data_new(xmlNode *node);
void pptx_ct_p_tliterate_data_free(pptx_ct_p_tliterate_data *obj);
pptx_ct_p_tliterate_interval_time *pptx_ct_p_tliterate_data_get_tm_abs(const pptx_ct_p_tliterate_data *const obj);
pptx_ct_p_tliterate_interval_percentage *pptx_ct_p_tliterate_data_get_tm_pct(const pptx_ct_p_tliterate_data *const obj);
pptx_st_iterate_type_token_enum pptx_ct_p_tliterate_data_get_type(const pptx_ct_p_tliterate_data *const obj);
pptx_bool pptx_ct_p_tliterate_data_get_backwards(const pptx_ct_p_tliterate_data *const obj);
int32_t pptx_ct_p_tliterate_data_get_index(pptx_ct_p_tliterate_data *obj);

#endif /* __PPTX_CT_P_TLITERATE_DATA_H__ */

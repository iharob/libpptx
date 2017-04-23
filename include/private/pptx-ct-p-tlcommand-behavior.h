#ifndef __PPTX_CT_P_TLCOMMAND_BEHAVIOR_H__
#define __PPTX_CT_P_TLCOMMAND_BEHAVIOR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tlcommon_behavior_data_s pptx_ct_p_tlcommon_behavior_data;
typedef enum pptx_st_tlcommand_type_token_enum pptx_st_tlcommand_type_token_enum;

typedef struct pptx_ct_p_tlcommand_behavior_s pptx_ct_p_tlcommand_behavior;
pptx_ct_p_tlcommand_behavior *pptx_ct_p_tlcommand_behavior_new(xmlNode *node);
void pptx_ct_p_tlcommand_behavior_free(pptx_ct_p_tlcommand_behavior *obj);
pptx_ct_p_tlcommon_behavior_data *pptx_ct_p_tlcommand_behavior_get_c_bhvr(const pptx_ct_p_tlcommand_behavior *const obj);
pptx_st_tlcommand_type_token_enum pptx_ct_p_tlcommand_behavior_get_type(const pptx_ct_p_tlcommand_behavior *const obj);
pptx_string pptx_ct_p_tlcommand_behavior_get_cmd(const pptx_ct_p_tlcommand_behavior *const obj);
int32_t pptx_ct_p_tlcommand_behavior_get_index(pptx_ct_p_tlcommand_behavior *obj);

#endif /* __PPTX_CT_P_TLCOMMAND_BEHAVIOR_H__ */

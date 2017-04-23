#ifndef __PPTX_CT_P_TLANIMATE_SCALE_BEHAVIOR_H__
#define __PPTX_CT_P_TLANIMATE_SCALE_BEHAVIOR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tlcommon_behavior_data_s pptx_ct_p_tlcommon_behavior_data;
typedef struct pptx_ct_p_tlpoint_s pptx_ct_p_tlpoint;

typedef struct pptx_ct_p_tlanimate_scale_behavior_s pptx_ct_p_tlanimate_scale_behavior;
pptx_ct_p_tlanimate_scale_behavior *pptx_ct_p_tlanimate_scale_behavior_new(xmlNode *node);
void pptx_ct_p_tlanimate_scale_behavior_free(pptx_ct_p_tlanimate_scale_behavior *obj);
pptx_ct_p_tlcommon_behavior_data *pptx_ct_p_tlanimate_scale_behavior_get_c_bhvr(const pptx_ct_p_tlanimate_scale_behavior *const obj);
pptx_ct_p_tlpoint *pptx_ct_p_tlanimate_scale_behavior_get_by(const pptx_ct_p_tlanimate_scale_behavior *const obj);
pptx_ct_p_tlpoint *pptx_ct_p_tlanimate_scale_behavior_get_from(const pptx_ct_p_tlanimate_scale_behavior *const obj);
pptx_ct_p_tlpoint *pptx_ct_p_tlanimate_scale_behavior_get_to(const pptx_ct_p_tlanimate_scale_behavior *const obj);
pptx_bool pptx_ct_p_tlanimate_scale_behavior_get_zoom_contents(const pptx_ct_p_tlanimate_scale_behavior *const obj);
int32_t pptx_ct_p_tlanimate_scale_behavior_get_index(pptx_ct_p_tlanimate_scale_behavior *obj);

#endif /* __PPTX_CT_P_TLANIMATE_SCALE_BEHAVIOR_H__ */

#ifndef __PPTX_CT_P_WHEEL_TRANSITION_H__
#define __PPTX_CT_P_WHEEL_TRANSITION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_wheel_transition_s pptx_ct_p_wheel_transition;
pptx_ct_p_wheel_transition *pptx_ct_p_wheel_transition_new(xmlNode *node);
void pptx_ct_p_wheel_transition_free(pptx_ct_p_wheel_transition *obj);
pptx_uint pptx_ct_p_wheel_transition_get_spokes(const pptx_ct_p_wheel_transition *const obj);
int32_t pptx_ct_p_wheel_transition_get_index(pptx_ct_p_wheel_transition *obj);

#endif /* __PPTX_CT_P_WHEEL_TRANSITION_H__ */

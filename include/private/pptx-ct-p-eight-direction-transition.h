#ifndef __PPTX_CT_P_EIGHT_DIRECTION_TRANSITION_H__
#define __PPTX_CT_P_EIGHT_DIRECTION_TRANSITION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_transition_corner_direction_type_token_enum pptx_st_transition_corner_direction_type_token_enum;

typedef struct pptx_ct_p_eight_direction_transition_s pptx_ct_p_eight_direction_transition;
pptx_ct_p_eight_direction_transition *pptx_ct_p_eight_direction_transition_new(xmlNode *node);
void pptx_ct_p_eight_direction_transition_free(pptx_ct_p_eight_direction_transition *obj);
pptx_st_transition_corner_direction_type_token_enum pptx_ct_p_eight_direction_transition_get_dir(const pptx_ct_p_eight_direction_transition *const obj);
int32_t pptx_ct_p_eight_direction_transition_get_index(pptx_ct_p_eight_direction_transition *obj);

#endif /* __PPTX_CT_P_EIGHT_DIRECTION_TRANSITION_H__ */

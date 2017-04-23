#ifndef __PPTX_CT_P_OPTIONAL_BLACK_TRANSITION_H__
#define __PPTX_CT_P_OPTIONAL_BLACK_TRANSITION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_optional_black_transition_s pptx_ct_p_optional_black_transition;
pptx_ct_p_optional_black_transition *pptx_ct_p_optional_black_transition_new(xmlNode *node);
void pptx_ct_p_optional_black_transition_free(pptx_ct_p_optional_black_transition *obj);
pptx_bool pptx_ct_p_optional_black_transition_get_thru_blk(const pptx_ct_p_optional_black_transition *const obj);
int32_t pptx_ct_p_optional_black_transition_get_index(pptx_ct_p_optional_black_transition *obj);

#endif /* __PPTX_CT_P_OPTIONAL_BLACK_TRANSITION_H__ */

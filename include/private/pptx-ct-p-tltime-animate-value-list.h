#ifndef __PPTX_CT_P_TLTIME_ANIMATE_VALUE_LIST_H__
#define __PPTX_CT_P_TLTIME_ANIMATE_VALUE_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tltime_animate_value_s pptx_ct_p_tltime_animate_value;

typedef struct pptx_ct_p_tltime_animate_value_list_s pptx_ct_p_tltime_animate_value_list;
pptx_ct_p_tltime_animate_value_list *pptx_ct_p_tltime_animate_value_list_new(xmlNode *node);
void pptx_ct_p_tltime_animate_value_list_free(pptx_ct_p_tltime_animate_value_list *obj);
pptx_ct_p_tltime_animate_value **pptx_ct_p_tltime_animate_value_list_get_tav(const pptx_ct_p_tltime_animate_value_list *const obj);
int32_t pptx_ct_p_tltime_animate_value_list_get_index(pptx_ct_p_tltime_animate_value_list *obj);

#endif /* __PPTX_CT_P_TLTIME_ANIMATE_VALUE_LIST_H__ */

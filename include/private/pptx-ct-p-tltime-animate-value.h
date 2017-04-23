#ifndef __PPTX_CT_P_TLTIME_ANIMATE_VALUE_H__
#define __PPTX_CT_P_TLTIME_ANIMATE_VALUE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tlanim_variant_s pptx_ct_p_tlanim_variant;
typedef enum pptx_st_tltime_indefinite_token_enum pptx_st_tltime_indefinite_token_enum;

typedef struct pptx_ct_p_tltime_animate_value_s pptx_ct_p_tltime_animate_value;
pptx_ct_p_tltime_animate_value *pptx_ct_p_tltime_animate_value_new(xmlNode *node);
void pptx_ct_p_tltime_animate_value_free(pptx_ct_p_tltime_animate_value *obj);
pptx_ct_p_tlanim_variant *pptx_ct_p_tltime_animate_value_get_val(const pptx_ct_p_tltime_animate_value *const obj);
pptx_st_tltime_indefinite_token_enum pptx_ct_p_tltime_animate_value_get_tm(const pptx_ct_p_tltime_animate_value *const obj);
pptx_string pptx_ct_p_tltime_animate_value_get_fmla(const pptx_ct_p_tltime_animate_value *const obj);
int32_t pptx_ct_p_tltime_animate_value_get_index(pptx_ct_p_tltime_animate_value *obj);

#endif /* __PPTX_CT_P_TLTIME_ANIMATE_VALUE_H__ */

#ifndef __PPTX_CT_A_ALPHA_MODULATE_FIXED_EFFECT_H__
#define __PPTX_CT_A_ALPHA_MODULATE_FIXED_EFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_alpha_modulate_fixed_effect_s pptx_ct_a_alpha_modulate_fixed_effect;
pptx_ct_a_alpha_modulate_fixed_effect *pptx_ct_a_alpha_modulate_fixed_effect_new(xmlNode *node);
void pptx_ct_a_alpha_modulate_fixed_effect_free(pptx_ct_a_alpha_modulate_fixed_effect *obj);
pptx_string pptx_ct_a_alpha_modulate_fixed_effect_get_amt(const pptx_ct_a_alpha_modulate_fixed_effect *const obj);
int32_t pptx_ct_a_alpha_modulate_fixed_effect_get_index(pptx_ct_a_alpha_modulate_fixed_effect *obj);

#endif /* __PPTX_CT_A_ALPHA_MODULATE_FIXED_EFFECT_H__ */

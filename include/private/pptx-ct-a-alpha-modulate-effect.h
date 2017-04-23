#ifndef __PPTX_CT_A_ALPHA_MODULATE_EFFECT_H__
#define __PPTX_CT_A_ALPHA_MODULATE_EFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_effect_container_s pptx_ct_a_effect_container;

typedef struct pptx_ct_a_alpha_modulate_effect_s pptx_ct_a_alpha_modulate_effect;
pptx_ct_a_alpha_modulate_effect *pptx_ct_a_alpha_modulate_effect_new(xmlNode *node);
void pptx_ct_a_alpha_modulate_effect_free(pptx_ct_a_alpha_modulate_effect *obj);
pptx_ct_a_effect_container *pptx_ct_a_alpha_modulate_effect_get_cont(const pptx_ct_a_alpha_modulate_effect *const obj);
int32_t pptx_ct_a_alpha_modulate_effect_get_index(pptx_ct_a_alpha_modulate_effect *obj);

#endif /* __PPTX_CT_A_ALPHA_MODULATE_EFFECT_H__ */

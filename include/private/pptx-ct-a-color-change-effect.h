#ifndef __PPTX_CT_A_COLOR_CHANGE_EFFECT_H__
#define __PPTX_CT_A_COLOR_CHANGE_EFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_color_s pptx_ct_a_color;

typedef struct pptx_ct_a_color_change_effect_s pptx_ct_a_color_change_effect;
pptx_ct_a_color_change_effect *pptx_ct_a_color_change_effect_new(xmlNode *node);
void pptx_ct_a_color_change_effect_free(pptx_ct_a_color_change_effect *obj);
pptx_ct_a_color *pptx_ct_a_color_change_effect_get_clr_from(const pptx_ct_a_color_change_effect *const obj);
pptx_ct_a_color *pptx_ct_a_color_change_effect_get_clr_to(const pptx_ct_a_color_change_effect *const obj);
pptx_bool pptx_ct_a_color_change_effect_get_use_a(const pptx_ct_a_color_change_effect *const obj);
int32_t pptx_ct_a_color_change_effect_get_index(pptx_ct_a_color_change_effect *obj);

#endif /* __PPTX_CT_A_COLOR_CHANGE_EFFECT_H__ */

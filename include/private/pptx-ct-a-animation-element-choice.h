#ifndef __PPTX_CT_A_ANIMATION_ELEMENT_CHOICE_H__
#define __PPTX_CT_A_ANIMATION_ELEMENT_CHOICE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_animation_dgm_element_s pptx_ct_a_animation_dgm_element;
typedef struct pptx_ct_a_animation_chart_element_s pptx_ct_a_animation_chart_element;

typedef struct pptx_ct_a_animation_element_choice_s pptx_ct_a_animation_element_choice;
pptx_ct_a_animation_element_choice *pptx_ct_a_animation_element_choice_new(xmlNode *node);
void pptx_ct_a_animation_element_choice_free(pptx_ct_a_animation_element_choice *obj);
pptx_ct_a_animation_dgm_element *pptx_ct_a_animation_element_choice_get_dgm(const pptx_ct_a_animation_element_choice *const obj);
pptx_ct_a_animation_chart_element *pptx_ct_a_animation_element_choice_get_chart(const pptx_ct_a_animation_element_choice *const obj);
int32_t pptx_ct_a_animation_element_choice_get_index(pptx_ct_a_animation_element_choice *obj);

#endif /* __PPTX_CT_A_ANIMATION_ELEMENT_CHOICE_H__ */

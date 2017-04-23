#ifndef __PPTX_CT_A_ANIMATION_CHART_ELEMENT_H__
#define __PPTX_CT_A_ANIMATION_CHART_ELEMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_chart_build_step_token_enum pptx_st_chart_build_step_token_enum;

typedef struct pptx_ct_a_animation_chart_element_s pptx_ct_a_animation_chart_element;
pptx_ct_a_animation_chart_element *pptx_ct_a_animation_chart_element_new(xmlNode *node);
void pptx_ct_a_animation_chart_element_free(pptx_ct_a_animation_chart_element *obj);
pptx_int pptx_ct_a_animation_chart_element_get_series_idx(const pptx_ct_a_animation_chart_element *const obj);
pptx_int pptx_ct_a_animation_chart_element_get_category_idx(const pptx_ct_a_animation_chart_element *const obj);
pptx_st_chart_build_step_token_enum pptx_ct_a_animation_chart_element_get_bld_step(const pptx_ct_a_animation_chart_element *const obj);
int32_t pptx_ct_a_animation_chart_element_get_index(pptx_ct_a_animation_chart_element *obj);

#endif /* __PPTX_CT_A_ANIMATION_CHART_ELEMENT_H__ */

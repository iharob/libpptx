#ifndef __PPTX_CT_P_TLOLE_CHART_TARGET_ELEMENT_H__
#define __PPTX_CT_P_TLOLE_CHART_TARGET_ELEMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlchart_subelement_type_token_enum pptx_st_tlchart_subelement_type_token_enum;

typedef struct pptx_ct_p_tlole_chart_target_element_s pptx_ct_p_tlole_chart_target_element;
pptx_ct_p_tlole_chart_target_element *pptx_ct_p_tlole_chart_target_element_new(xmlNode *node);
void pptx_ct_p_tlole_chart_target_element_free(pptx_ct_p_tlole_chart_target_element *obj);
pptx_st_tlchart_subelement_type_token_enum pptx_ct_p_tlole_chart_target_element_get_type(const pptx_ct_p_tlole_chart_target_element *const obj);
pptx_uint pptx_ct_p_tlole_chart_target_element_get_lvl(const pptx_ct_p_tlole_chart_target_element *const obj);
int32_t pptx_ct_p_tlole_chart_target_element_get_index(pptx_ct_p_tlole_chart_target_element *obj);

#endif /* __PPTX_CT_P_TLOLE_CHART_TARGET_ELEMENT_H__ */

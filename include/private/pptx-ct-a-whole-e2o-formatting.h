#ifndef __PPTX_CT_A_WHOLE_E2O_FORMATTING_H__
#define __PPTX_CT_A_WHOLE_E2O_FORMATTING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_line_properties_s pptx_ct_a_line_properties;
typedef struct pptx_ct_a_effect_list_s pptx_ct_a_effect_list;
typedef struct pptx_ct_a_effect_container_s pptx_ct_a_effect_container;

typedef struct pptx_ct_a_whole_e2o_formatting_s pptx_ct_a_whole_e2o_formatting;
pptx_ct_a_whole_e2o_formatting *pptx_ct_a_whole_e2o_formatting_new(xmlNode *node);
void pptx_ct_a_whole_e2o_formatting_free(pptx_ct_a_whole_e2o_formatting *obj);
pptx_ct_a_line_properties *pptx_ct_a_whole_e2o_formatting_get_ln(const pptx_ct_a_whole_e2o_formatting *const obj);
pptx_ct_a_effect_list *pptx_ct_a_whole_e2o_formatting_get_effect_properties_effect_lst(const pptx_ct_a_whole_e2o_formatting *const obj);
pptx_ct_a_effect_container *pptx_ct_a_whole_e2o_formatting_get_effect_properties_effect_dag(const pptx_ct_a_whole_e2o_formatting *const obj);
int32_t pptx_ct_a_whole_e2o_formatting_get_index(pptx_ct_a_whole_e2o_formatting *obj);

#endif /* __PPTX_CT_A_WHOLE_E2O_FORMATTING_H__ */

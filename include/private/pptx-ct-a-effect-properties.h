#ifndef __PPTX_CT_A_EFFECT_PROPERTIES_H__
#define __PPTX_CT_A_EFFECT_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_effect_list_s pptx_ct_a_effect_list;
typedef struct pptx_ct_a_effect_container_s pptx_ct_a_effect_container;

typedef struct pptx_ct_a_effect_properties_s pptx_ct_a_effect_properties;
pptx_ct_a_effect_properties *pptx_ct_a_effect_properties_new(xmlNode *node);
void pptx_ct_a_effect_properties_free(pptx_ct_a_effect_properties *obj);
pptx_ct_a_effect_list *pptx_ct_a_effect_properties_get_effect_properties_effect_lst(const pptx_ct_a_effect_properties *const obj);
pptx_ct_a_effect_container *pptx_ct_a_effect_properties_get_effect_properties_effect_dag(const pptx_ct_a_effect_properties *const obj);
int32_t pptx_ct_a_effect_properties_get_index(pptx_ct_a_effect_properties *obj);

#endif /* __PPTX_CT_A_EFFECT_PROPERTIES_H__ */

#ifndef __PPTX_CT_A_EFFECT_REFERENCE_H__
#define __PPTX_CT_A_EFFECT_REFERENCE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_effect_reference_s pptx_ct_a_effect_reference;
pptx_ct_a_effect_reference *pptx_ct_a_effect_reference_new(xmlNode *node);
void pptx_ct_a_effect_reference_free(pptx_ct_a_effect_reference *obj);
pptx_string pptx_ct_a_effect_reference_get_ref(const pptx_ct_a_effect_reference *const obj);
int32_t pptx_ct_a_effect_reference_get_index(pptx_ct_a_effect_reference *obj);

#endif /* __PPTX_CT_A_EFFECT_REFERENCE_H__ */

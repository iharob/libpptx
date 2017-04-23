#ifndef __PPTX_CT_A_TRANSFORM_EFFECT_H__
#define __PPTX_CT_A_TRANSFORM_EFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_transform_effect_s pptx_ct_a_transform_effect;
pptx_ct_a_transform_effect *pptx_ct_a_transform_effect_new(xmlNode *node);
void pptx_ct_a_transform_effect_free(pptx_ct_a_transform_effect *obj);
pptx_string pptx_ct_a_transform_effect_get_sx(const pptx_ct_a_transform_effect *const obj);
pptx_string pptx_ct_a_transform_effect_get_sy(const pptx_ct_a_transform_effect *const obj);
pptx_int pptx_ct_a_transform_effect_get_kx(const pptx_ct_a_transform_effect *const obj);
pptx_int pptx_ct_a_transform_effect_get_ky(const pptx_ct_a_transform_effect *const obj);
pptx_string pptx_ct_a_transform_effect_get_tx(const pptx_ct_a_transform_effect *const obj);
pptx_string pptx_ct_a_transform_effect_get_ty(const pptx_ct_a_transform_effect *const obj);
int32_t pptx_ct_a_transform_effect_get_index(pptx_ct_a_transform_effect *obj);

#endif /* __PPTX_CT_A_TRANSFORM_EFFECT_H__ */

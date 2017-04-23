#ifndef __PPTX_CT_A_GRAYSCALE_EFFECT_H__
#define __PPTX_CT_A_GRAYSCALE_EFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_grayscale_effect_s pptx_ct_a_grayscale_effect;
pptx_ct_a_grayscale_effect *pptx_ct_a_grayscale_effect_new(xmlNode *node);
void pptx_ct_a_grayscale_effect_free(pptx_ct_a_grayscale_effect *obj);
int32_t pptx_ct_a_grayscale_effect_get_index(pptx_ct_a_grayscale_effect *obj);

#endif /* __PPTX_CT_A_GRAYSCALE_EFFECT_H__ */

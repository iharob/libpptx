#ifndef __PPTX_CT_A_HSLEFFECT_H__
#define __PPTX_CT_A_HSLEFFECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_hsleffect_s pptx_ct_a_hsleffect;
pptx_ct_a_hsleffect *pptx_ct_a_hsleffect_new(xmlNode *node);
void pptx_ct_a_hsleffect_free(pptx_ct_a_hsleffect *obj);
pptx_int pptx_ct_a_hsleffect_get_hue(const pptx_ct_a_hsleffect *const obj);
pptx_string pptx_ct_a_hsleffect_get_sat(const pptx_ct_a_hsleffect *const obj);
pptx_string pptx_ct_a_hsleffect_get_lum(const pptx_ct_a_hsleffect *const obj);
int32_t pptx_ct_a_hsleffect_get_index(pptx_ct_a_hsleffect *obj);

#endif /* __PPTX_CT_A_HSLEFFECT_H__ */

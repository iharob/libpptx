#ifndef __PPTX_CT_A_TEXT_NORMAL_AUTOFIT_H__
#define __PPTX_CT_A_TEXT_NORMAL_AUTOFIT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_text_normal_autofit_s pptx_ct_a_text_normal_autofit;
pptx_ct_a_text_normal_autofit *pptx_ct_a_text_normal_autofit_new(xmlNode *node);
void pptx_ct_a_text_normal_autofit_free(pptx_ct_a_text_normal_autofit *obj);
pptx_string pptx_ct_a_text_normal_autofit_get_font_scale(const pptx_ct_a_text_normal_autofit *const obj);
pptx_string pptx_ct_a_text_normal_autofit_get_ln_spc_reduction(const pptx_ct_a_text_normal_autofit *const obj);
int32_t pptx_ct_a_text_normal_autofit_get_index(pptx_ct_a_text_normal_autofit *obj);

#endif /* __PPTX_CT_A_TEXT_NORMAL_AUTOFIT_H__ */

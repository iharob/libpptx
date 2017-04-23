#ifndef __PPTX_CT_A_TEXT_SPACING_PERCENT_H__
#define __PPTX_CT_A_TEXT_SPACING_PERCENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_text_spacing_percent_s pptx_ct_a_text_spacing_percent;
pptx_ct_a_text_spacing_percent *pptx_ct_a_text_spacing_percent_new(xmlNode *node);
void pptx_ct_a_text_spacing_percent_free(pptx_ct_a_text_spacing_percent *obj);
pptx_string pptx_ct_a_text_spacing_percent_get_val(const pptx_ct_a_text_spacing_percent *const obj);
int32_t pptx_ct_a_text_spacing_percent_get_index(pptx_ct_a_text_spacing_percent *obj);

#endif /* __PPTX_CT_A_TEXT_SPACING_PERCENT_H__ */

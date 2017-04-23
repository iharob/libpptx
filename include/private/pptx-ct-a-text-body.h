#ifndef __PPTX_CT_A_TEXT_BODY_H__
#define __PPTX_CT_A_TEXT_BODY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_body_properties_s pptx_ct_a_text_body_properties;
typedef struct pptx_ct_a_text_list_style_s pptx_ct_a_text_list_style;
typedef struct pptx_ct_a_text_paragraph_s pptx_ct_a_text_paragraph;

typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
pptx_ct_a_text_body *pptx_ct_a_text_body_new(xmlNode *node);
void pptx_ct_a_text_body_free(pptx_ct_a_text_body *obj);
pptx_ct_a_text_body_properties *pptx_ct_a_text_body_get_body_pr(const pptx_ct_a_text_body *const obj);
pptx_ct_a_text_list_style *pptx_ct_a_text_body_get_lst_style(const pptx_ct_a_text_body *const obj);
pptx_ct_a_text_paragraph **pptx_ct_a_text_body_get_p(const pptx_ct_a_text_body *const obj);
int32_t pptx_ct_a_text_body_get_index(pptx_ct_a_text_body *obj);

#endif /* __PPTX_CT_A_TEXT_BODY_H__ */

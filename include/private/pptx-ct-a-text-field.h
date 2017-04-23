#ifndef __PPTX_CT_A_TEXT_FIELD_H__
#define __PPTX_CT_A_TEXT_FIELD_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_character_properties_s pptx_ct_a_text_character_properties;
typedef struct pptx_ct_a_text_paragraph_properties_s pptx_ct_a_text_paragraph_properties;

typedef struct pptx_ct_a_text_field_s pptx_ct_a_text_field;
pptx_ct_a_text_field *pptx_ct_a_text_field_new(xmlNode *node);
void pptx_ct_a_text_field_free(pptx_ct_a_text_field *obj);
pptx_ct_a_text_character_properties *pptx_ct_a_text_field_get_r_pr(const pptx_ct_a_text_field *const obj);
pptx_ct_a_text_paragraph_properties *pptx_ct_a_text_field_get_p_pr(const pptx_ct_a_text_field *const obj);
pptx_string pptx_ct_a_text_field_get_t(const pptx_ct_a_text_field *const obj);
pptx_string pptx_ct_a_text_field_get_id(const pptx_ct_a_text_field *const obj);
pptx_string pptx_ct_a_text_field_get_type(const pptx_ct_a_text_field *const obj);
int32_t pptx_ct_a_text_field_get_index(pptx_ct_a_text_field *obj);

#endif /* __PPTX_CT_A_TEXT_FIELD_H__ */

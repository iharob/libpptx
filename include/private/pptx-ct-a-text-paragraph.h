#ifndef __PPTX_CT_A_TEXT_PARAGRAPH_H__
#define __PPTX_CT_A_TEXT_PARAGRAPH_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_paragraph_properties_s pptx_ct_a_text_paragraph_properties;
typedef struct pptx_ct_a_regular_text_run_s pptx_ct_a_regular_text_run;
typedef struct pptx_ct_a_text_line_break_s pptx_ct_a_text_line_break;
typedef struct pptx_ct_a_text_field_s pptx_ct_a_text_field;
typedef struct pptx_ct_a_text_character_properties_s pptx_ct_a_text_character_properties;

typedef struct pptx_ct_a_text_paragraph_s pptx_ct_a_text_paragraph;
pptx_ct_a_text_paragraph *pptx_ct_a_text_paragraph_new(xmlNode *node);
void pptx_ct_a_text_paragraph_free(pptx_ct_a_text_paragraph *obj);
pptx_ct_a_text_paragraph_properties *pptx_ct_a_text_paragraph_get_p_pr(const pptx_ct_a_text_paragraph *const obj);
pptx_ct_a_regular_text_run **pptx_ct_a_text_paragraph_get_text_run_r(const pptx_ct_a_text_paragraph *const obj);
pptx_ct_a_text_line_break **pptx_ct_a_text_paragraph_get_text_run_br(const pptx_ct_a_text_paragraph *const obj);
pptx_ct_a_text_field **pptx_ct_a_text_paragraph_get_text_run_fld(const pptx_ct_a_text_paragraph *const obj);
pptx_ct_a_text_character_properties *pptx_ct_a_text_paragraph_get_end_para_rpr(const pptx_ct_a_text_paragraph *const obj);
int32_t pptx_ct_a_text_paragraph_get_index(pptx_ct_a_text_paragraph *obj);

#endif /* __PPTX_CT_A_TEXT_PARAGRAPH_H__ */

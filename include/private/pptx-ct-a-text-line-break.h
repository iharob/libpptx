#ifndef __PPTX_CT_A_TEXT_LINE_BREAK_H__
#define __PPTX_CT_A_TEXT_LINE_BREAK_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_character_properties_s pptx_ct_a_text_character_properties;

typedef struct pptx_ct_a_text_line_break_s pptx_ct_a_text_line_break;
pptx_ct_a_text_line_break *pptx_ct_a_text_line_break_new(xmlNode *node);
void pptx_ct_a_text_line_break_free(pptx_ct_a_text_line_break *obj);
pptx_ct_a_text_character_properties *pptx_ct_a_text_line_break_get_r_pr(const pptx_ct_a_text_line_break *const obj);
int32_t pptx_ct_a_text_line_break_get_index(pptx_ct_a_text_line_break *obj);

#endif /* __PPTX_CT_A_TEXT_LINE_BREAK_H__ */

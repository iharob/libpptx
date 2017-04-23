#ifndef __PPTX_CT_A_TEXT_UNDERLINE_LINE_FOLLOW_TEXT_H__
#define __PPTX_CT_A_TEXT_UNDERLINE_LINE_FOLLOW_TEXT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_text_underline_line_follow_text_s pptx_ct_a_text_underline_line_follow_text;
pptx_ct_a_text_underline_line_follow_text *pptx_ct_a_text_underline_line_follow_text_new(xmlNode *node);
void pptx_ct_a_text_underline_line_follow_text_free(pptx_ct_a_text_underline_line_follow_text *obj);
int32_t pptx_ct_a_text_underline_line_follow_text_get_index(pptx_ct_a_text_underline_line_follow_text *obj);

#endif /* __PPTX_CT_A_TEXT_UNDERLINE_LINE_FOLLOW_TEXT_H__ */

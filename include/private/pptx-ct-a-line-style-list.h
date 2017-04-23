#ifndef __PPTX_CT_A_LINE_STYLE_LIST_H__
#define __PPTX_CT_A_LINE_STYLE_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_line_properties_s pptx_ct_a_line_properties;

typedef struct pptx_ct_a_line_style_list_s pptx_ct_a_line_style_list;
pptx_ct_a_line_style_list *pptx_ct_a_line_style_list_new(xmlNode *node);
void pptx_ct_a_line_style_list_free(pptx_ct_a_line_style_list *obj);
pptx_ct_a_line_properties **pptx_ct_a_line_style_list_get_ln(const pptx_ct_a_line_style_list *const obj);
int32_t pptx_ct_a_line_style_list_get_index(pptx_ct_a_line_style_list *obj);

#endif /* __PPTX_CT_A_LINE_STYLE_LIST_H__ */

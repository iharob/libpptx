#ifndef __PPTX_CT_A_HEADER_FOOTER_H__
#define __PPTX_CT_A_HEADER_FOOTER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_header_footer_s pptx_ct_a_header_footer;
pptx_ct_a_header_footer *pptx_ct_a_header_footer_new(xmlNode *node);
void pptx_ct_a_header_footer_free(pptx_ct_a_header_footer *obj);
pptx_string pptx_ct_a_header_footer_get_odd_header(const pptx_ct_a_header_footer *const obj);
pptx_string pptx_ct_a_header_footer_get_odd_footer(const pptx_ct_a_header_footer *const obj);
pptx_string pptx_ct_a_header_footer_get_even_header(const pptx_ct_a_header_footer *const obj);
pptx_string pptx_ct_a_header_footer_get_even_footer(const pptx_ct_a_header_footer *const obj);
pptx_string pptx_ct_a_header_footer_get_first_header(const pptx_ct_a_header_footer *const obj);
pptx_string pptx_ct_a_header_footer_get_first_footer(const pptx_ct_a_header_footer *const obj);
pptx_bool pptx_ct_a_header_footer_get_align_with_margins(const pptx_ct_a_header_footer *const obj);
pptx_bool pptx_ct_a_header_footer_get_different_odd_even(const pptx_ct_a_header_footer *const obj);
pptx_bool pptx_ct_a_header_footer_get_different_first(const pptx_ct_a_header_footer *const obj);
int32_t pptx_ct_a_header_footer_get_index(pptx_ct_a_header_footer *obj);

#endif /* __PPTX_CT_A_HEADER_FOOTER_H__ */

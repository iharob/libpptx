#ifndef __PPTX_CT_A_PAGE_MARGINS_H__
#define __PPTX_CT_A_PAGE_MARGINS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_page_margins_s pptx_ct_a_page_margins;
pptx_ct_a_page_margins *pptx_ct_a_page_margins_new(xmlNode *node);
void pptx_ct_a_page_margins_free(pptx_ct_a_page_margins *obj);
pptx_double pptx_ct_a_page_margins_get_l(const pptx_ct_a_page_margins *const obj);
pptx_double pptx_ct_a_page_margins_get_r(const pptx_ct_a_page_margins *const obj);
pptx_double pptx_ct_a_page_margins_get_t(const pptx_ct_a_page_margins *const obj);
pptx_double pptx_ct_a_page_margins_get_b(const pptx_ct_a_page_margins *const obj);
pptx_double pptx_ct_a_page_margins_get_header(const pptx_ct_a_page_margins *const obj);
pptx_double pptx_ct_a_page_margins_get_footer(const pptx_ct_a_page_margins *const obj);
int32_t pptx_ct_a_page_margins_get_index(pptx_ct_a_page_margins *obj);

#endif /* __PPTX_CT_A_PAGE_MARGINS_H__ */

#ifndef __PPTX_CT_A_PAGE_SETUP_H__
#define __PPTX_CT_A_PAGE_SETUP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_page_setup_orientation_text_enum pptx_st_page_setup_orientation_text_enum;

typedef struct pptx_ct_a_page_setup_s pptx_ct_a_page_setup;
pptx_ct_a_page_setup *pptx_ct_a_page_setup_new(xmlNode *node);
void pptx_ct_a_page_setup_free(pptx_ct_a_page_setup *obj);
pptx_uint pptx_ct_a_page_setup_get_paper_size(const pptx_ct_a_page_setup *const obj);
pptx_string pptx_ct_a_page_setup_get_paper_height(const pptx_ct_a_page_setup *const obj);
pptx_string pptx_ct_a_page_setup_get_paper_width(const pptx_ct_a_page_setup *const obj);
pptx_uint pptx_ct_a_page_setup_get_first_page_number(const pptx_ct_a_page_setup *const obj);
pptx_st_page_setup_orientation_text_enum pptx_ct_a_page_setup_get_orientation(const pptx_ct_a_page_setup *const obj);
pptx_bool pptx_ct_a_page_setup_get_black_and_white(const pptx_ct_a_page_setup *const obj);
pptx_bool pptx_ct_a_page_setup_get_draft(const pptx_ct_a_page_setup *const obj);
pptx_bool pptx_ct_a_page_setup_get_use_first_page_number(const pptx_ct_a_page_setup *const obj);
pptx_int pptx_ct_a_page_setup_get_horizontal_dpi(const pptx_ct_a_page_setup *const obj);
pptx_int pptx_ct_a_page_setup_get_vertical_dpi(const pptx_ct_a_page_setup *const obj);
pptx_uint pptx_ct_a_page_setup_get_copies(const pptx_ct_a_page_setup *const obj);
int32_t pptx_ct_a_page_setup_get_index(pptx_ct_a_page_setup *obj);

#endif /* __PPTX_CT_A_PAGE_SETUP_H__ */

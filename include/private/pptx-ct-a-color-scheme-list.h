#ifndef __PPTX_CT_A_COLOR_SCHEME_LIST_H__
#define __PPTX_CT_A_COLOR_SCHEME_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_color_scheme_and_mapping_s pptx_ct_a_color_scheme_and_mapping;

typedef struct pptx_ct_a_color_scheme_list_s pptx_ct_a_color_scheme_list;
pptx_ct_a_color_scheme_list *pptx_ct_a_color_scheme_list_new(xmlNode *node);
void pptx_ct_a_color_scheme_list_free(pptx_ct_a_color_scheme_list *obj);
pptx_ct_a_color_scheme_and_mapping **pptx_ct_a_color_scheme_list_get_extra_clr_scheme(const pptx_ct_a_color_scheme_list *const obj);
int32_t pptx_ct_a_color_scheme_list_get_index(pptx_ct_a_color_scheme_list *obj);

#endif /* __PPTX_CT_A_COLOR_SCHEME_LIST_H__ */

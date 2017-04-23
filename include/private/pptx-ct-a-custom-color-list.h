#ifndef __PPTX_CT_A_CUSTOM_COLOR_LIST_H__
#define __PPTX_CT_A_CUSTOM_COLOR_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_custom_color_s pptx_ct_a_custom_color;

typedef struct pptx_ct_a_custom_color_list_s pptx_ct_a_custom_color_list;
pptx_ct_a_custom_color_list *pptx_ct_a_custom_color_list_new(xmlNode *node);
void pptx_ct_a_custom_color_list_free(pptx_ct_a_custom_color_list *obj);
pptx_ct_a_custom_color **pptx_ct_a_custom_color_list_get_cust_clr(const pptx_ct_a_custom_color_list *const obj);
int32_t pptx_ct_a_custom_color_list_get_index(pptx_ct_a_custom_color_list *obj);

#endif /* __PPTX_CT_A_CUSTOM_COLOR_LIST_H__ */

#ifndef __PPTX_CT_A_TEXT_TAB_STOP_LIST_H__
#define __PPTX_CT_A_TEXT_TAB_STOP_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_tab_stop_s pptx_ct_a_text_tab_stop;

typedef struct pptx_ct_a_text_tab_stop_list_s pptx_ct_a_text_tab_stop_list;
pptx_ct_a_text_tab_stop_list *pptx_ct_a_text_tab_stop_list_new(xmlNode *node);
void pptx_ct_a_text_tab_stop_list_free(pptx_ct_a_text_tab_stop_list *obj);
pptx_ct_a_text_tab_stop **pptx_ct_a_text_tab_stop_list_get_tab(const pptx_ct_a_text_tab_stop_list *const obj);
int32_t pptx_ct_a_text_tab_stop_list_get_index(pptx_ct_a_text_tab_stop_list *obj);

#endif /* __PPTX_CT_A_TEXT_TAB_STOP_LIST_H__ */

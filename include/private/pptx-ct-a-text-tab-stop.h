#ifndef __PPTX_CT_A_TEXT_TAB_STOP_H__
#define __PPTX_CT_A_TEXT_TAB_STOP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_text_tab_align_type_token_enum pptx_st_text_tab_align_type_token_enum;

typedef struct pptx_ct_a_text_tab_stop_s pptx_ct_a_text_tab_stop;
pptx_ct_a_text_tab_stop *pptx_ct_a_text_tab_stop_new(xmlNode *node);
void pptx_ct_a_text_tab_stop_free(pptx_ct_a_text_tab_stop *obj);
pptx_string pptx_ct_a_text_tab_stop_get_pos(const pptx_ct_a_text_tab_stop *const obj);
pptx_st_text_tab_align_type_token_enum pptx_ct_a_text_tab_stop_get_algn(const pptx_ct_a_text_tab_stop *const obj);
int32_t pptx_ct_a_text_tab_stop_get_index(pptx_ct_a_text_tab_stop *obj);

#endif /* __PPTX_CT_A_TEXT_TAB_STOP_H__ */

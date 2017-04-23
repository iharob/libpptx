#ifndef __PPTX_CT_A_TITLE_H__
#define __PPTX_CT_A_TITLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_tx_s pptx_ct_a_tx;
typedef struct pptx_ct_a_layout_s pptx_ct_a_layout;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_title_s pptx_ct_a_title;
pptx_ct_a_title *pptx_ct_a_title_new(xmlNode *node);
void pptx_ct_a_title_free(pptx_ct_a_title *obj);
pptx_ct_a_tx *pptx_ct_a_title_get_tx(const pptx_ct_a_title *const obj);
pptx_ct_a_layout *pptx_ct_a_title_get_layout(const pptx_ct_a_title *const obj);
pptx_bool pptx_ct_a_title_get_overlay(const pptx_ct_a_title *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_title_get_sp_pr(const pptx_ct_a_title *const obj);
pptx_ct_a_text_body *pptx_ct_a_title_get_tx_pr(const pptx_ct_a_title *const obj);
pptx_ct_a_extension_list *pptx_ct_a_title_get_ext_lst(const pptx_ct_a_title *const obj);
int32_t pptx_ct_a_title_get_index(pptx_ct_a_title *obj);

#endif /* __PPTX_CT_A_TITLE_H__ */

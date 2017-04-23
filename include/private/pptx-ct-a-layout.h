#ifndef __PPTX_CT_A_LAYOUT_H__
#define __PPTX_CT_A_LAYOUT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_manual_layout_s pptx_ct_a_manual_layout;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_layout_s pptx_ct_a_layout;
pptx_ct_a_layout *pptx_ct_a_layout_new(xmlNode *node);
void pptx_ct_a_layout_free(pptx_ct_a_layout *obj);
pptx_ct_a_manual_layout *pptx_ct_a_layout_get_manual_layout(const pptx_ct_a_layout *const obj);
pptx_ct_a_extension_list *pptx_ct_a_layout_get_ext_lst(const pptx_ct_a_layout *const obj);
int32_t pptx_ct_a_layout_get_index(pptx_ct_a_layout *obj);

#endif /* __PPTX_CT_A_LAYOUT_H__ */

#ifndef __PPTX_CT_A_LEGEND_ENTRY_H__
#define __PPTX_CT_A_LEGEND_ENTRY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_legend_entry_s pptx_ct_a_legend_entry;
pptx_ct_a_legend_entry *pptx_ct_a_legend_entry_new(xmlNode *node);
void pptx_ct_a_legend_entry_free(pptx_ct_a_legend_entry *obj);
pptx_uint pptx_ct_a_legend_entry_get_idx(const pptx_ct_a_legend_entry *const obj);
pptx_bool pptx_ct_a_legend_entry_get_delete(const pptx_ct_a_legend_entry *const obj);
pptx_ct_a_text_body *pptx_ct_a_legend_entry_get_legend_entry_data_tx_pr(const pptx_ct_a_legend_entry *const obj);
pptx_ct_a_extension_list *pptx_ct_a_legend_entry_get_ext_lst(const pptx_ct_a_legend_entry *const obj);
int32_t pptx_ct_a_legend_entry_get_index(pptx_ct_a_legend_entry *obj);

#endif /* __PPTX_CT_A_LEGEND_ENTRY_H__ */

#ifndef __PPTX_CT_A_TABLE_STYLE_LIST_H__
#define __PPTX_CT_A_TABLE_STYLE_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_table_style_s pptx_ct_a_table_style;

typedef struct pptx_ct_a_table_style_list_s pptx_ct_a_table_style_list;
pptx_ct_a_table_style_list *pptx_ct_a_table_style_list_new(xmlNode *node);
void pptx_ct_a_table_style_list_free(pptx_ct_a_table_style_list *obj);
pptx_ct_a_table_style **pptx_ct_a_table_style_list_get_tbl_style(const pptx_ct_a_table_style_list *const obj);
pptx_string pptx_ct_a_table_style_list_get_def(const pptx_ct_a_table_style_list *const obj);
int32_t pptx_ct_a_table_style_list_get_index(pptx_ct_a_table_style_list *obj);

#endif /* __PPTX_CT_A_TABLE_STYLE_LIST_H__ */

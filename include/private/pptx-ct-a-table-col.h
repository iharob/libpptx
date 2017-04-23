#ifndef __PPTX_CT_A_TABLE_COL_H__
#define __PPTX_CT_A_TABLE_COL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_table_col_s pptx_ct_a_table_col;
pptx_ct_a_table_col *pptx_ct_a_table_col_new(xmlNode *node);
void pptx_ct_a_table_col_free(pptx_ct_a_table_col *obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_table_col_get_ext_lst(const pptx_ct_a_table_col *const obj);
pptx_string pptx_ct_a_table_col_get_w(const pptx_ct_a_table_col *const obj);
int32_t pptx_ct_a_table_col_get_index(pptx_ct_a_table_col *obj);

#endif /* __PPTX_CT_A_TABLE_COL_H__ */

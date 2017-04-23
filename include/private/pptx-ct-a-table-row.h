#ifndef __PPTX_CT_A_TABLE_ROW_H__
#define __PPTX_CT_A_TABLE_ROW_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_table_cell_s pptx_ct_a_table_cell;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_table_row_s pptx_ct_a_table_row;
pptx_ct_a_table_row *pptx_ct_a_table_row_new(xmlNode *node);
void pptx_ct_a_table_row_free(pptx_ct_a_table_row *obj);
pptx_ct_a_table_cell **pptx_ct_a_table_row_get_tc(const pptx_ct_a_table_row *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_table_row_get_ext_lst(const pptx_ct_a_table_row *const obj);
pptx_string pptx_ct_a_table_row_get_h(const pptx_ct_a_table_row *const obj);
int32_t pptx_ct_a_table_row_get_index(pptx_ct_a_table_row *obj);

#endif /* __PPTX_CT_A_TABLE_ROW_H__ */

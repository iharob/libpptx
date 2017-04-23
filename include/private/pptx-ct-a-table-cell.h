#ifndef __PPTX_CT_A_TABLE_CELL_H__
#define __PPTX_CT_A_TABLE_CELL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_table_cell_properties_s pptx_ct_a_table_cell_properties;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_table_cell_s pptx_ct_a_table_cell;
pptx_ct_a_table_cell *pptx_ct_a_table_cell_new(xmlNode *node);
void pptx_ct_a_table_cell_free(pptx_ct_a_table_cell *obj);
pptx_ct_a_text_body *pptx_ct_a_table_cell_get_tx_body(const pptx_ct_a_table_cell *const obj);
pptx_ct_a_table_cell_properties *pptx_ct_a_table_cell_get_tc_pr(const pptx_ct_a_table_cell *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_table_cell_get_ext_lst(const pptx_ct_a_table_cell *const obj);
pptx_int pptx_ct_a_table_cell_get_row_span(const pptx_ct_a_table_cell *const obj);
pptx_int pptx_ct_a_table_cell_get_grid_span(const pptx_ct_a_table_cell *const obj);
pptx_bool pptx_ct_a_table_cell_get_h_merge(const pptx_ct_a_table_cell *const obj);
pptx_bool pptx_ct_a_table_cell_get_v_merge(const pptx_ct_a_table_cell *const obj);
pptx_string pptx_ct_a_table_cell_get_id(const pptx_ct_a_table_cell *const obj);
int32_t pptx_ct_a_table_cell_get_index(pptx_ct_a_table_cell *obj);

#endif /* __PPTX_CT_A_TABLE_CELL_H__ */

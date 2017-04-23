#ifndef __PPTX_CT_A_TABLE_H__
#define __PPTX_CT_A_TABLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_table_properties_s pptx_ct_a_table_properties;
typedef struct pptx_ct_a_table_grid_s pptx_ct_a_table_grid;
typedef struct pptx_ct_a_table_row_s pptx_ct_a_table_row;

typedef struct pptx_ct_a_table_s pptx_ct_a_table;
pptx_ct_a_table *pptx_ct_a_table_new(xmlNode *node);
void pptx_ct_a_table_free(pptx_ct_a_table *obj);
pptx_ct_a_table_properties *pptx_ct_a_table_get_tbl_pr(const pptx_ct_a_table *const obj);
pptx_ct_a_table_grid *pptx_ct_a_table_get_tbl_grid(const pptx_ct_a_table *const obj);
pptx_ct_a_table_row **pptx_ct_a_table_get_tr(const pptx_ct_a_table *const obj);
int32_t pptx_ct_a_table_get_index(pptx_ct_a_table *obj);

#endif /* __PPTX_CT_A_TABLE_H__ */

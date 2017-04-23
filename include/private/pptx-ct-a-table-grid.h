#ifndef __PPTX_CT_A_TABLE_GRID_H__
#define __PPTX_CT_A_TABLE_GRID_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_table_col_s pptx_ct_a_table_col;

typedef struct pptx_ct_a_table_grid_s pptx_ct_a_table_grid;
pptx_ct_a_table_grid *pptx_ct_a_table_grid_new(xmlNode *node);
void pptx_ct_a_table_grid_free(pptx_ct_a_table_grid *obj);
pptx_ct_a_table_col **pptx_ct_a_table_grid_get_grid_col(const pptx_ct_a_table_grid *const obj);
int32_t pptx_ct_a_table_grid_get_index(pptx_ct_a_table_grid *obj);

#endif /* __PPTX_CT_A_TABLE_GRID_H__ */

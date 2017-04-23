#ifndef __PPTX_CT_A_TABLE_PART_STYLE_H__
#define __PPTX_CT_A_TABLE_PART_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_table_style_text_style_s pptx_ct_a_table_style_text_style;
typedef struct pptx_ct_a_table_style_cell_style_s pptx_ct_a_table_style_cell_style;

typedef struct pptx_ct_a_table_part_style_s pptx_ct_a_table_part_style;
pptx_ct_a_table_part_style *pptx_ct_a_table_part_style_new(xmlNode *node);
void pptx_ct_a_table_part_style_free(pptx_ct_a_table_part_style *obj);
pptx_ct_a_table_style_text_style *pptx_ct_a_table_part_style_get_tc_tx_style(const pptx_ct_a_table_part_style *const obj);
pptx_ct_a_table_style_cell_style *pptx_ct_a_table_part_style_get_tc_style(const pptx_ct_a_table_part_style *const obj);
int32_t pptx_ct_a_table_part_style_get_index(pptx_ct_a_table_part_style *obj);

#endif /* __PPTX_CT_A_TABLE_PART_STYLE_H__ */

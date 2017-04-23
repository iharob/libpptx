#ifndef __PPTX_CT_A_TABLE_STYLE_H__
#define __PPTX_CT_A_TABLE_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_table_background_style_s pptx_ct_a_table_background_style;
typedef struct pptx_ct_a_table_part_style_s pptx_ct_a_table_part_style;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_table_style_s pptx_ct_a_table_style;
pptx_ct_a_table_style *pptx_ct_a_table_style_new(xmlNode *node);
void pptx_ct_a_table_style_free(pptx_ct_a_table_style *obj);
pptx_ct_a_table_background_style *pptx_ct_a_table_style_get_tbl_bg(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_whole_tbl(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_band1_h(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_band2_h(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_band1_v(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_band2_v(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_last_col(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_first_col(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_last_row(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_se_cell(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_sw_cell(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_first_row(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_ne_cell(const pptx_ct_a_table_style *const obj);
pptx_ct_a_table_part_style *pptx_ct_a_table_style_get_nw_cell(const pptx_ct_a_table_style *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_table_style_get_ext_lst(const pptx_ct_a_table_style *const obj);
pptx_string pptx_ct_a_table_style_get_style_id(const pptx_ct_a_table_style *const obj);
pptx_string pptx_ct_a_table_style_get_style_name(const pptx_ct_a_table_style *const obj);
int32_t pptx_ct_a_table_style_get_index(pptx_ct_a_table_style *obj);

#endif /* __PPTX_CT_A_TABLE_STYLE_H__ */

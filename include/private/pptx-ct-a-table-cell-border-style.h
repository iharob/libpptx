#ifndef __PPTX_CT_A_TABLE_CELL_BORDER_STYLE_H__
#define __PPTX_CT_A_TABLE_CELL_BORDER_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_themeable_line_style_s pptx_ct_a_themeable_line_style;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_table_cell_border_style_s pptx_ct_a_table_cell_border_style;
pptx_ct_a_table_cell_border_style *pptx_ct_a_table_cell_border_style_new(xmlNode *node);
void pptx_ct_a_table_cell_border_style_free(pptx_ct_a_table_cell_border_style *obj);
pptx_ct_a_themeable_line_style *pptx_ct_a_table_cell_border_style_get_left(const pptx_ct_a_table_cell_border_style *const obj);
pptx_ct_a_themeable_line_style *pptx_ct_a_table_cell_border_style_get_right(const pptx_ct_a_table_cell_border_style *const obj);
pptx_ct_a_themeable_line_style *pptx_ct_a_table_cell_border_style_get_top(const pptx_ct_a_table_cell_border_style *const obj);
pptx_ct_a_themeable_line_style *pptx_ct_a_table_cell_border_style_get_bottom(const pptx_ct_a_table_cell_border_style *const obj);
pptx_ct_a_themeable_line_style *pptx_ct_a_table_cell_border_style_get_inside_h(const pptx_ct_a_table_cell_border_style *const obj);
pptx_ct_a_themeable_line_style *pptx_ct_a_table_cell_border_style_get_inside_v(const pptx_ct_a_table_cell_border_style *const obj);
pptx_ct_a_themeable_line_style *pptx_ct_a_table_cell_border_style_get_tl2br(const pptx_ct_a_table_cell_border_style *const obj);
pptx_ct_a_themeable_line_style *pptx_ct_a_table_cell_border_style_get_tr2bl(const pptx_ct_a_table_cell_border_style *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_table_cell_border_style_get_ext_lst(const pptx_ct_a_table_cell_border_style *const obj);
int32_t pptx_ct_a_table_cell_border_style_get_index(pptx_ct_a_table_cell_border_style *obj);

#endif /* __PPTX_CT_A_TABLE_CELL_BORDER_STYLE_H__ */

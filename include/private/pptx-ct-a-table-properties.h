#ifndef __PPTX_CT_A_TABLE_PROPERTIES_H__
#define __PPTX_CT_A_TABLE_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_no_fill_properties_s pptx_ct_a_no_fill_properties;
typedef struct pptx_ct_a_solid_color_fill_properties_s pptx_ct_a_solid_color_fill_properties;
typedef struct pptx_ct_a_gradient_fill_properties_s pptx_ct_a_gradient_fill_properties;
typedef struct pptx_ct_a_blip_fill_properties_s pptx_ct_a_blip_fill_properties;
typedef struct pptx_ct_a_pattern_fill_properties_s pptx_ct_a_pattern_fill_properties;
typedef struct pptx_ct_a_group_fill_properties_s pptx_ct_a_group_fill_properties;
typedef struct pptx_ct_a_effect_list_s pptx_ct_a_effect_list;
typedef struct pptx_ct_a_effect_container_s pptx_ct_a_effect_container;
typedef struct pptx_ct_a_table_style_s pptx_ct_a_table_style;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_table_properties_s pptx_ct_a_table_properties;
pptx_ct_a_table_properties *pptx_ct_a_table_properties_new(xmlNode *node);
void pptx_ct_a_table_properties_free(pptx_ct_a_table_properties *obj);
pptx_ct_a_no_fill_properties *pptx_ct_a_table_properties_get_fill_properties_no_fill(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_solid_color_fill_properties *pptx_ct_a_table_properties_get_fill_properties_solid_fill(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_gradient_fill_properties *pptx_ct_a_table_properties_get_fill_properties_grad_fill(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_blip_fill_properties *pptx_ct_a_table_properties_get_fill_properties_blip_fill(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_pattern_fill_properties *pptx_ct_a_table_properties_get_fill_properties_patt_fill(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_group_fill_properties *pptx_ct_a_table_properties_get_fill_properties_grp_fill(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_effect_list *pptx_ct_a_table_properties_get_effect_properties_effect_lst(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_effect_container *pptx_ct_a_table_properties_get_effect_properties_effect_dag(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_table_style *pptx_ct_a_table_properties_get_table_style(const pptx_ct_a_table_properties *const obj);
pptx_string pptx_ct_a_table_properties_get_table_style_id(const pptx_ct_a_table_properties *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_table_properties_get_ext_lst(const pptx_ct_a_table_properties *const obj);
pptx_bool pptx_ct_a_table_properties_get_rtl(const pptx_ct_a_table_properties *const obj);
pptx_bool pptx_ct_a_table_properties_get_first_row(const pptx_ct_a_table_properties *const obj);
pptx_bool pptx_ct_a_table_properties_get_first_col(const pptx_ct_a_table_properties *const obj);
pptx_bool pptx_ct_a_table_properties_get_last_row(const pptx_ct_a_table_properties *const obj);
pptx_bool pptx_ct_a_table_properties_get_last_col(const pptx_ct_a_table_properties *const obj);
pptx_bool pptx_ct_a_table_properties_get_band_row(const pptx_ct_a_table_properties *const obj);
pptx_bool pptx_ct_a_table_properties_get_band_col(const pptx_ct_a_table_properties *const obj);
int32_t pptx_ct_a_table_properties_get_index(pptx_ct_a_table_properties *obj);

#endif /* __PPTX_CT_A_TABLE_PROPERTIES_H__ */

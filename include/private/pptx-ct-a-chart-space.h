#ifndef __PPTX_CT_A_CHART_SPACE_H__
#define __PPTX_CT_A_CHART_SPACE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_language_id_s pptx_ct_a_text_language_id;
typedef struct pptx_ct_a_style_s pptx_ct_a_style;
typedef struct pptx_ct_a_color_mapping_s pptx_ct_a_color_mapping;
typedef struct pptx_ct_a_pivot_source_s pptx_ct_a_pivot_source;
typedef struct pptx_ct_a_protection_s pptx_ct_a_protection;
typedef struct pptx_ct_a_chart_s pptx_ct_a_chart;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_external_data_s pptx_ct_a_external_data;
typedef struct pptx_ct_a_print_settings_s pptx_ct_a_print_settings;
typedef struct pptx_ct_a_rel_id_s pptx_ct_a_rel_id;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_chart_space_s pptx_ct_a_chart_space;
pptx_ct_a_chart_space *pptx_ct_a_chart_space_new(xmlNode *node);
void pptx_ct_a_chart_space_free(pptx_ct_a_chart_space *obj);
pptx_bool pptx_ct_a_chart_space_get_date1904(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_text_language_id *pptx_ct_a_chart_space_get_lang(const pptx_ct_a_chart_space *const obj);
pptx_bool pptx_ct_a_chart_space_get_rounded_corners(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_style *pptx_ct_a_chart_space_get_style(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_color_mapping *pptx_ct_a_chart_space_get_clr_map_ovr(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_pivot_source *pptx_ct_a_chart_space_get_pivot_source(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_protection *pptx_ct_a_chart_space_get_protection(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_chart *pptx_ct_a_chart_space_get_chart(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_chart_space_get_sp_pr(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_text_body *pptx_ct_a_chart_space_get_tx_pr(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_external_data *pptx_ct_a_chart_space_get_external_data(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_print_settings *pptx_ct_a_chart_space_get_print_settings(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_rel_id *pptx_ct_a_chart_space_get_user_shapes(const pptx_ct_a_chart_space *const obj);
pptx_ct_a_extension_list *pptx_ct_a_chart_space_get_ext_lst(const pptx_ct_a_chart_space *const obj);
int32_t pptx_ct_a_chart_space_get_index(pptx_ct_a_chart_space *obj);

#endif /* __PPTX_CT_A_CHART_SPACE_H__ */

#ifndef __PPTX_CT_P_SHOW_PROPERTIES_H__
#define __PPTX_CT_P_SHOW_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_empty_s pptx_ct_p_empty;
typedef struct pptx_ct_p_show_info_browse_s pptx_ct_p_show_info_browse;
typedef struct pptx_ct_p_show_info_kiosk_s pptx_ct_p_show_info_kiosk;
typedef struct pptx_ct_p_index_range_s pptx_ct_p_index_range;
typedef struct pptx_ct_p_custom_show_id_s pptx_ct_p_custom_show_id;
typedef struct pptx_ct_a_color_s pptx_ct_a_color;
typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;

typedef struct pptx_ct_p_show_properties_s pptx_ct_p_show_properties;
pptx_ct_p_show_properties *pptx_ct_p_show_properties_new(xmlNode *node);
void pptx_ct_p_show_properties_free(pptx_ct_p_show_properties *obj);
pptx_ct_p_empty *pptx_ct_p_show_properties_get_show_type_present(const pptx_ct_p_show_properties *const obj);
pptx_ct_p_show_info_browse *pptx_ct_p_show_properties_get_show_type_browse(const pptx_ct_p_show_properties *const obj);
pptx_ct_p_show_info_kiosk *pptx_ct_p_show_properties_get_show_type_kiosk(const pptx_ct_p_show_properties *const obj);
pptx_ct_p_empty *pptx_ct_p_show_properties_get_slide_list_choice_sld_all(const pptx_ct_p_show_properties *const obj);
pptx_ct_p_index_range *pptx_ct_p_show_properties_get_slide_list_choice_sld_rg(const pptx_ct_p_show_properties *const obj);
pptx_ct_p_custom_show_id *pptx_ct_p_show_properties_get_slide_list_choice_cust_show(const pptx_ct_p_show_properties *const obj);
pptx_ct_a_color *pptx_ct_p_show_properties_get_pen_clr(const pptx_ct_p_show_properties *const obj);
pptx_ct_p_extension_list *pptx_ct_p_show_properties_get_ext_lst(const pptx_ct_p_show_properties *const obj);
pptx_bool pptx_ct_p_show_properties_get_loop(const pptx_ct_p_show_properties *const obj);
pptx_bool pptx_ct_p_show_properties_get_show_narration(const pptx_ct_p_show_properties *const obj);
pptx_bool pptx_ct_p_show_properties_get_show_animation(const pptx_ct_p_show_properties *const obj);
pptx_bool pptx_ct_p_show_properties_get_use_timings(const pptx_ct_p_show_properties *const obj);
int32_t pptx_ct_p_show_properties_get_index(pptx_ct_p_show_properties *obj);

#endif /* __PPTX_CT_P_SHOW_PROPERTIES_H__ */

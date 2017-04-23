#ifndef __PPTX_CT_P_SLIDE_LAYOUT_H__
#define __PPTX_CT_P_SLIDE_LAYOUT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_common_slide_data_s pptx_ct_p_common_slide_data;
typedef struct pptx_ct_a_color_mapping_override_s pptx_ct_a_color_mapping_override;
typedef struct pptx_ct_p_slide_transition_s pptx_ct_p_slide_transition;
typedef struct pptx_ct_p_slide_timing_s pptx_ct_p_slide_timing;
typedef struct pptx_ct_p_header_footer_s pptx_ct_p_header_footer;
typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;
typedef enum pptx_st_slide_layout_type_token_enum pptx_st_slide_layout_type_token_enum;

typedef struct pptx_ct_p_slide_layout_s pptx_ct_p_slide_layout;
pptx_ct_p_slide_layout *pptx_ct_p_slide_layout_new(xmlNode *node);
void pptx_ct_p_slide_layout_free(pptx_ct_p_slide_layout *obj);
pptx_ct_p_common_slide_data *pptx_ct_p_slide_layout_get_c_sld(const pptx_ct_p_slide_layout *const obj);
pptx_ct_a_color_mapping_override *pptx_ct_p_slide_layout_get_child_slide_clr_map_ovr(const pptx_ct_p_slide_layout *const obj);
pptx_ct_p_slide_transition *pptx_ct_p_slide_layout_get_transition(const pptx_ct_p_slide_layout *const obj);
pptx_ct_p_slide_timing *pptx_ct_p_slide_layout_get_timing(const pptx_ct_p_slide_layout *const obj);
pptx_ct_p_header_footer *pptx_ct_p_slide_layout_get_hf(const pptx_ct_p_slide_layout *const obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_slide_layout_get_ext_lst(const pptx_ct_p_slide_layout *const obj);
pptx_bool pptx_ct_p_slide_layout_get_show_master_sp(const pptx_ct_p_slide_layout *const obj);
pptx_bool pptx_ct_p_slide_layout_get_show_master_ph_anim(const pptx_ct_p_slide_layout *const obj);
pptx_string pptx_ct_p_slide_layout_get_matching_name(const pptx_ct_p_slide_layout *const obj);
pptx_st_slide_layout_type_token_enum pptx_ct_p_slide_layout_get_type(const pptx_ct_p_slide_layout *const obj);
pptx_bool pptx_ct_p_slide_layout_get_preserve(const pptx_ct_p_slide_layout *const obj);
pptx_bool pptx_ct_p_slide_layout_get_user_drawn(const pptx_ct_p_slide_layout *const obj);
int32_t pptx_ct_p_slide_layout_get_index(pptx_ct_p_slide_layout *obj);

#endif /* __PPTX_CT_P_SLIDE_LAYOUT_H__ */

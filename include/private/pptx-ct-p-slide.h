#ifndef __PPTX_CT_P_SLIDE_H__
#define __PPTX_CT_P_SLIDE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_common_slide_data_s pptx_ct_p_common_slide_data;
typedef struct pptx_ct_a_color_mapping_override_s pptx_ct_a_color_mapping_override;
typedef struct pptx_ct_p_slide_transition_s pptx_ct_p_slide_transition;
typedef struct pptx_ct_p_slide_timing_s pptx_ct_p_slide_timing;
typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;

typedef struct pptx_ct_p_slide_s pptx_ct_p_slide;
pptx_ct_p_slide *pptx_ct_p_slide_new(xmlNode *node);
void pptx_ct_p_slide_free(pptx_ct_p_slide *obj);
pptx_ct_p_common_slide_data *pptx_ct_p_slide_get_c_sld(const pptx_ct_p_slide *const obj);
pptx_ct_a_color_mapping_override *pptx_ct_p_slide_get_child_slide_clr_map_ovr(const pptx_ct_p_slide *const obj);
pptx_ct_p_slide_transition *pptx_ct_p_slide_get_transition(const pptx_ct_p_slide *const obj);
pptx_ct_p_slide_timing *pptx_ct_p_slide_get_timing(const pptx_ct_p_slide *const obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_slide_get_ext_lst(const pptx_ct_p_slide *const obj);
pptx_bool pptx_ct_p_slide_get_show_master_sp(const pptx_ct_p_slide *const obj);
pptx_bool pptx_ct_p_slide_get_show_master_ph_anim(const pptx_ct_p_slide *const obj);
pptx_bool pptx_ct_p_slide_get_show(const pptx_ct_p_slide *const obj);
int32_t pptx_ct_p_slide_get_index(pptx_ct_p_slide *obj);

#endif /* __PPTX_CT_P_SLIDE_H__ */

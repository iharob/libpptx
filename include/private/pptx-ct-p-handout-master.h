#ifndef __PPTX_CT_P_HANDOUT_MASTER_H__
#define __PPTX_CT_P_HANDOUT_MASTER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_common_slide_data_s pptx_ct_p_common_slide_data;
typedef struct pptx_ct_a_color_mapping_s pptx_ct_a_color_mapping;
typedef struct pptx_ct_p_header_footer_s pptx_ct_p_header_footer;
typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;

typedef struct pptx_ct_p_handout_master_s pptx_ct_p_handout_master;
pptx_ct_p_handout_master *pptx_ct_p_handout_master_new(xmlNode *node);
void pptx_ct_p_handout_master_free(pptx_ct_p_handout_master *obj);
pptx_ct_p_common_slide_data *pptx_ct_p_handout_master_get_c_sld(const pptx_ct_p_handout_master *const obj);
pptx_ct_a_color_mapping *pptx_ct_p_handout_master_get_top_level_slide_clr_map(const pptx_ct_p_handout_master *const obj);
pptx_ct_p_header_footer *pptx_ct_p_handout_master_get_hf(const pptx_ct_p_handout_master *const obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_handout_master_get_ext_lst(const pptx_ct_p_handout_master *const obj);
int32_t pptx_ct_p_handout_master_get_index(pptx_ct_p_handout_master *obj);

#endif /* __PPTX_CT_P_HANDOUT_MASTER_H__ */

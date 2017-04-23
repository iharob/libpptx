#ifndef __PPTX_CT_A_DPT_H__
#define __PPTX_CT_A_DPT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_marker_s pptx_ct_a_marker;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_picture_options_s pptx_ct_a_picture_options;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_dpt_s pptx_ct_a_dpt;
pptx_ct_a_dpt *pptx_ct_a_dpt_new(xmlNode *node);
void pptx_ct_a_dpt_free(pptx_ct_a_dpt *obj);
pptx_uint pptx_ct_a_dpt_get_idx(const pptx_ct_a_dpt *const obj);
pptx_bool pptx_ct_a_dpt_get_invert_if_negative(const pptx_ct_a_dpt *const obj);
pptx_ct_a_marker *pptx_ct_a_dpt_get_marker(const pptx_ct_a_dpt *const obj);
pptx_bool pptx_ct_a_dpt_get_bubble_3d(const pptx_ct_a_dpt *const obj);
pptx_uint pptx_ct_a_dpt_get_explosion(const pptx_ct_a_dpt *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_dpt_get_sp_pr(const pptx_ct_a_dpt *const obj);
pptx_ct_a_picture_options *pptx_ct_a_dpt_get_picture_options(const pptx_ct_a_dpt *const obj);
pptx_ct_a_extension_list *pptx_ct_a_dpt_get_ext_lst(const pptx_ct_a_dpt *const obj);
int32_t pptx_ct_a_dpt_get_index(pptx_ct_a_dpt *obj);

#endif /* __PPTX_CT_A_DPT_H__ */

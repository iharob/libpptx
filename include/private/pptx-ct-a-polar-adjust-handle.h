#ifndef __PPTX_CT_A_POLAR_ADJUST_HANDLE_H__
#define __PPTX_CT_A_POLAR_ADJUST_HANDLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_adj_point_2d_s pptx_ct_a_adj_point_2d;

typedef struct pptx_ct_a_polar_adjust_handle_s pptx_ct_a_polar_adjust_handle;
pptx_ct_a_polar_adjust_handle *pptx_ct_a_polar_adjust_handle_new(xmlNode *node);
void pptx_ct_a_polar_adjust_handle_free(pptx_ct_a_polar_adjust_handle *obj);
pptx_ct_a_adj_point_2d *pptx_ct_a_polar_adjust_handle_get_pos(const pptx_ct_a_polar_adjust_handle *const obj);
pptx_string pptx_ct_a_polar_adjust_handle_get_gd_ref_r(const pptx_ct_a_polar_adjust_handle *const obj);
pptx_string pptx_ct_a_polar_adjust_handle_get_min_r(const pptx_ct_a_polar_adjust_handle *const obj);
pptx_string pptx_ct_a_polar_adjust_handle_get_max_r(const pptx_ct_a_polar_adjust_handle *const obj);
pptx_string pptx_ct_a_polar_adjust_handle_get_gd_ref_ang(const pptx_ct_a_polar_adjust_handle *const obj);
pptx_string pptx_ct_a_polar_adjust_handle_get_min_ang(const pptx_ct_a_polar_adjust_handle *const obj);
pptx_string pptx_ct_a_polar_adjust_handle_get_max_ang(const pptx_ct_a_polar_adjust_handle *const obj);
int32_t pptx_ct_a_polar_adjust_handle_get_index(pptx_ct_a_polar_adjust_handle *obj);

#endif /* __PPTX_CT_A_POLAR_ADJUST_HANDLE_H__ */

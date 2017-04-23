#ifndef __PPTX_CT_A_VIEW_3D_H__
#define __PPTX_CT_A_VIEW_3D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_rot_x_s pptx_ct_a_rot_x;
typedef struct pptx_ct_a_hpercent_s pptx_ct_a_hpercent;
typedef struct pptx_ct_a_rot_y_s pptx_ct_a_rot_y;
typedef struct pptx_ct_a_depth_percent_s pptx_ct_a_depth_percent;
typedef struct pptx_ct_a_perspective_s pptx_ct_a_perspective;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_view_3d_s pptx_ct_a_view_3d;
pptx_ct_a_view_3d *pptx_ct_a_view_3d_new(xmlNode *node);
void pptx_ct_a_view_3d_free(pptx_ct_a_view_3d *obj);
pptx_ct_a_rot_x *pptx_ct_a_view_3d_get_rot_x(const pptx_ct_a_view_3d *const obj);
pptx_ct_a_hpercent *pptx_ct_a_view_3d_get_h_percent(const pptx_ct_a_view_3d *const obj);
pptx_ct_a_rot_y *pptx_ct_a_view_3d_get_rot_y(const pptx_ct_a_view_3d *const obj);
pptx_ct_a_depth_percent *pptx_ct_a_view_3d_get_depth_percent(const pptx_ct_a_view_3d *const obj);
pptx_bool pptx_ct_a_view_3d_get_r_ang_ax(const pptx_ct_a_view_3d *const obj);
pptx_ct_a_perspective *pptx_ct_a_view_3d_get_perspective(const pptx_ct_a_view_3d *const obj);
pptx_ct_a_extension_list *pptx_ct_a_view_3d_get_ext_lst(const pptx_ct_a_view_3d *const obj);
int32_t pptx_ct_a_view_3d_get_index(pptx_ct_a_view_3d *obj);

#endif /* __PPTX_CT_A_VIEW_3D_H__ */

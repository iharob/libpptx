#ifndef __PPTX_CT_A_GROUP_TRANSFORM_2D_H__
#define __PPTX_CT_A_GROUP_TRANSFORM_2D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_point_2d_s pptx_ct_a_point_2d;
typedef struct pptx_ct_a_positive_size_2d_s pptx_ct_a_positive_size_2d;

typedef struct pptx_ct_a_group_transform_2d_s pptx_ct_a_group_transform_2d;
pptx_ct_a_group_transform_2d *pptx_ct_a_group_transform_2d_new(xmlNode *node);
void pptx_ct_a_group_transform_2d_free(pptx_ct_a_group_transform_2d *obj);
pptx_ct_a_point_2d *pptx_ct_a_group_transform_2d_get_off(const pptx_ct_a_group_transform_2d *const obj);
pptx_ct_a_positive_size_2d *pptx_ct_a_group_transform_2d_get_ext(const pptx_ct_a_group_transform_2d *const obj);
pptx_ct_a_point_2d *pptx_ct_a_group_transform_2d_get_ch_off(const pptx_ct_a_group_transform_2d *const obj);
pptx_ct_a_positive_size_2d *pptx_ct_a_group_transform_2d_get_ch_ext(const pptx_ct_a_group_transform_2d *const obj);
pptx_int pptx_ct_a_group_transform_2d_get_rot(const pptx_ct_a_group_transform_2d *const obj);
pptx_bool pptx_ct_a_group_transform_2d_get_flip_h(const pptx_ct_a_group_transform_2d *const obj);
pptx_bool pptx_ct_a_group_transform_2d_get_flip_v(const pptx_ct_a_group_transform_2d *const obj);
int32_t pptx_ct_a_group_transform_2d_get_index(pptx_ct_a_group_transform_2d *obj);

#endif /* __PPTX_CT_A_GROUP_TRANSFORM_2D_H__ */

#ifndef __PPTX_CT_A_SHAPE_3D_H__
#define __PPTX_CT_A_SHAPE_3D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_bevel_s pptx_ct_a_bevel;
typedef struct pptx_ct_a_color_s pptx_ct_a_color;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_preset_material_type_token_enum pptx_st_preset_material_type_token_enum;

typedef struct pptx_ct_a_shape_3d_s pptx_ct_a_shape_3d;
pptx_ct_a_shape_3d *pptx_ct_a_shape_3d_new(xmlNode *node);
void pptx_ct_a_shape_3d_free(pptx_ct_a_shape_3d *obj);
pptx_ct_a_bevel *pptx_ct_a_shape_3d_get_bevel_t(const pptx_ct_a_shape_3d *const obj);
pptx_ct_a_bevel *pptx_ct_a_shape_3d_get_bevel_b(const pptx_ct_a_shape_3d *const obj);
pptx_ct_a_color *pptx_ct_a_shape_3d_get_extrusion_clr(const pptx_ct_a_shape_3d *const obj);
pptx_ct_a_color *pptx_ct_a_shape_3d_get_contour_clr(const pptx_ct_a_shape_3d *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_shape_3d_get_ext_lst(const pptx_ct_a_shape_3d *const obj);
pptx_string pptx_ct_a_shape_3d_get_z(const pptx_ct_a_shape_3d *const obj);
pptx_long pptx_ct_a_shape_3d_get_extrusion_h(const pptx_ct_a_shape_3d *const obj);
pptx_long pptx_ct_a_shape_3d_get_contour_w(const pptx_ct_a_shape_3d *const obj);
pptx_st_preset_material_type_token_enum pptx_ct_a_shape_3d_get_prst_material(const pptx_ct_a_shape_3d *const obj);
int32_t pptx_ct_a_shape_3d_get_index(pptx_ct_a_shape_3d *obj);

#endif /* __PPTX_CT_A_SHAPE_3D_H__ */

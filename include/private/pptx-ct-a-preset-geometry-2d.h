#ifndef __PPTX_CT_A_PRESET_GEOMETRY_2D_H__
#define __PPTX_CT_A_PRESET_GEOMETRY_2D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_geom_guide_list_s pptx_ct_a_geom_guide_list;
typedef enum pptx_st_shape_type_token_enum pptx_st_shape_type_token_enum;

typedef struct pptx_ct_a_preset_geometry_2d_s pptx_ct_a_preset_geometry_2d;
pptx_ct_a_preset_geometry_2d *pptx_ct_a_preset_geometry_2d_new(xmlNode *node);
void pptx_ct_a_preset_geometry_2d_free(pptx_ct_a_preset_geometry_2d *obj);
pptx_ct_a_geom_guide_list *pptx_ct_a_preset_geometry_2d_get_av_lst(const pptx_ct_a_preset_geometry_2d *const obj);
pptx_st_shape_type_token_enum pptx_ct_a_preset_geometry_2d_get_prst(const pptx_ct_a_preset_geometry_2d *const obj);
int32_t pptx_ct_a_preset_geometry_2d_get_index(pptx_ct_a_preset_geometry_2d *obj);

#endif /* __PPTX_CT_A_PRESET_GEOMETRY_2D_H__ */

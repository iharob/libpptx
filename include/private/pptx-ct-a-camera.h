#ifndef __PPTX_CT_A_CAMERA_H__
#define __PPTX_CT_A_CAMERA_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_sphere_coords_s pptx_ct_a_sphere_coords;
typedef enum pptx_st_preset_camera_type_token_enum pptx_st_preset_camera_type_token_enum;

typedef struct pptx_ct_a_camera_s pptx_ct_a_camera;
pptx_ct_a_camera *pptx_ct_a_camera_new(xmlNode *node);
void pptx_ct_a_camera_free(pptx_ct_a_camera *obj);
pptx_ct_a_sphere_coords *pptx_ct_a_camera_get_rot(const pptx_ct_a_camera *const obj);
pptx_st_preset_camera_type_token_enum pptx_ct_a_camera_get_prst(const pptx_ct_a_camera *const obj);
pptx_int pptx_ct_a_camera_get_fov(const pptx_ct_a_camera *const obj);
pptx_string pptx_ct_a_camera_get_zoom(const pptx_ct_a_camera *const obj);
int32_t pptx_ct_a_camera_get_index(pptx_ct_a_camera *obj);

#endif /* __PPTX_CT_A_CAMERA_H__ */

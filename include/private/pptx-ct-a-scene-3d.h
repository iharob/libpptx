#ifndef __PPTX_CT_A_SCENE_3D_H__
#define __PPTX_CT_A_SCENE_3D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_camera_s pptx_ct_a_camera;
typedef struct pptx_ct_a_light_rig_s pptx_ct_a_light_rig;
typedef struct pptx_ct_a_backdrop_s pptx_ct_a_backdrop;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_scene_3d_s pptx_ct_a_scene_3d;
pptx_ct_a_scene_3d *pptx_ct_a_scene_3d_new(xmlNode *node);
void pptx_ct_a_scene_3d_free(pptx_ct_a_scene_3d *obj);
pptx_ct_a_camera *pptx_ct_a_scene_3d_get_camera(const pptx_ct_a_scene_3d *const obj);
pptx_ct_a_light_rig *pptx_ct_a_scene_3d_get_light_rig(const pptx_ct_a_scene_3d *const obj);
pptx_ct_a_backdrop *pptx_ct_a_scene_3d_get_backdrop(const pptx_ct_a_scene_3d *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_scene_3d_get_ext_lst(const pptx_ct_a_scene_3d *const obj);
int32_t pptx_ct_a_scene_3d_get_index(pptx_ct_a_scene_3d *obj);

#endif /* __PPTX_CT_A_SCENE_3D_H__ */

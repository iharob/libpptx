#ifndef __PPTX_CT_A_LIGHT_RIG_H__
#define __PPTX_CT_A_LIGHT_RIG_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_sphere_coords_s pptx_ct_a_sphere_coords;
typedef enum pptx_st_light_rig_type_token_enum pptx_st_light_rig_type_token_enum;
typedef enum pptx_st_light_rig_direction_token_enum pptx_st_light_rig_direction_token_enum;

typedef struct pptx_ct_a_light_rig_s pptx_ct_a_light_rig;
pptx_ct_a_light_rig *pptx_ct_a_light_rig_new(xmlNode *node);
void pptx_ct_a_light_rig_free(pptx_ct_a_light_rig *obj);
pptx_ct_a_sphere_coords *pptx_ct_a_light_rig_get_rot(const pptx_ct_a_light_rig *const obj);
pptx_st_light_rig_type_token_enum pptx_ct_a_light_rig_get_rig(const pptx_ct_a_light_rig *const obj);
pptx_st_light_rig_direction_token_enum pptx_ct_a_light_rig_get_dir(const pptx_ct_a_light_rig *const obj);
int32_t pptx_ct_a_light_rig_get_index(pptx_ct_a_light_rig *obj);

#endif /* __PPTX_CT_A_LIGHT_RIG_H__ */

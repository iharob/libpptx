#ifndef __PPTX_CT_P_GROUP_SHAPE_H__
#define __PPTX_CT_P_GROUP_SHAPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_group_shape_non_visual_s pptx_ct_p_group_shape_non_visual;
typedef struct pptx_ct_a_group_shape_properties_s pptx_ct_a_group_shape_properties;
typedef struct pptx_ct_p_shape_s pptx_ct_p_shape;
typedef struct pptx_ct_p_group_shape_s pptx_ct_p_group_shape;
typedef struct pptx_ct_p_graphical_object_frame_s pptx_ct_p_graphical_object_frame;
typedef struct pptx_ct_p_connector_s pptx_ct_p_connector;
typedef struct pptx_ct_p_picture_s pptx_ct_p_picture;
typedef struct pptx_ct_p_rel_s pptx_ct_p_rel;
typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;

typedef struct pptx_ct_p_group_shape_s pptx_ct_p_group_shape;
pptx_ct_p_group_shape *pptx_ct_p_group_shape_new(xmlNode *node);
void pptx_ct_p_group_shape_free(pptx_ct_p_group_shape *obj);
pptx_ct_p_group_shape_non_visual *pptx_ct_p_group_shape_get_nv_grp_sp_pr(const pptx_ct_p_group_shape *const obj);
pptx_ct_a_group_shape_properties *pptx_ct_p_group_shape_get_grp_sp_pr(const pptx_ct_p_group_shape *const obj);
pptx_ct_p_shape **pptx_ct_p_group_shape_get_sp(const pptx_ct_p_group_shape *const obj);
pptx_ct_p_group_shape **pptx_ct_p_group_shape_get_grp_sp(const pptx_ct_p_group_shape *const obj);
pptx_ct_p_graphical_object_frame **pptx_ct_p_group_shape_get_graphic_frame(const pptx_ct_p_group_shape *const obj);
pptx_ct_p_connector **pptx_ct_p_group_shape_get_cxn_sp(const pptx_ct_p_group_shape *const obj);
pptx_ct_p_picture **pptx_ct_p_group_shape_get_pic(const pptx_ct_p_group_shape *const obj);
pptx_ct_p_rel **pptx_ct_p_group_shape_get_content_part(const pptx_ct_p_group_shape *const obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_group_shape_get_ext_lst(const pptx_ct_p_group_shape *const obj);
int32_t pptx_ct_p_group_shape_get_index(pptx_ct_p_group_shape *obj);

#endif /* __PPTX_CT_P_GROUP_SHAPE_H__ */

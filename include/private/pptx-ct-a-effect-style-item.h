#ifndef __PPTX_CT_A_EFFECT_STYLE_ITEM_H__
#define __PPTX_CT_A_EFFECT_STYLE_ITEM_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_effect_list_s pptx_ct_a_effect_list;
typedef struct pptx_ct_a_effect_container_s pptx_ct_a_effect_container;
typedef struct pptx_ct_a_scene_3d_s pptx_ct_a_scene_3d;
typedef struct pptx_ct_a_shape_3d_s pptx_ct_a_shape_3d;

typedef struct pptx_ct_a_effect_style_item_s pptx_ct_a_effect_style_item;
pptx_ct_a_effect_style_item *pptx_ct_a_effect_style_item_new(xmlNode *node);
void pptx_ct_a_effect_style_item_free(pptx_ct_a_effect_style_item *obj);
pptx_ct_a_effect_list *pptx_ct_a_effect_style_item_get_effect_properties_effect_lst(const pptx_ct_a_effect_style_item *const obj);
pptx_ct_a_effect_container *pptx_ct_a_effect_style_item_get_effect_properties_effect_dag(const pptx_ct_a_effect_style_item *const obj);
pptx_ct_a_scene_3d *pptx_ct_a_effect_style_item_get_scene3d(const pptx_ct_a_effect_style_item *const obj);
pptx_ct_a_shape_3d *pptx_ct_a_effect_style_item_get_sp3d(const pptx_ct_a_effect_style_item *const obj);
int32_t pptx_ct_a_effect_style_item_get_index(pptx_ct_a_effect_style_item *obj);

#endif /* __PPTX_CT_A_EFFECT_STYLE_ITEM_H__ */

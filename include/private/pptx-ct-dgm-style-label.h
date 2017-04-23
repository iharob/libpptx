#ifndef __PPTX_CT_DGM_STYLE_LABEL_H__
#define __PPTX_CT_DGM_STYLE_LABEL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_scene_3d_s pptx_ct_a_scene_3d;
typedef struct pptx_ct_a_shape_3d_s pptx_ct_a_shape_3d;
typedef struct pptx_ct_dgm_text_props_s pptx_ct_dgm_text_props;
typedef struct pptx_ct_a_shape_style_s pptx_ct_a_shape_style;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_dgm_style_label_s pptx_ct_dgm_style_label;
pptx_ct_dgm_style_label *pptx_ct_dgm_style_label_new(xmlNode *node);
void pptx_ct_dgm_style_label_free(pptx_ct_dgm_style_label *obj);
pptx_ct_a_scene_3d *pptx_ct_dgm_style_label_get_scene3d(const pptx_ct_dgm_style_label *const obj);
pptx_ct_a_shape_3d *pptx_ct_dgm_style_label_get_sp3d(const pptx_ct_dgm_style_label *const obj);
pptx_ct_dgm_text_props *pptx_ct_dgm_style_label_get_tx_pr(const pptx_ct_dgm_style_label *const obj);
pptx_ct_a_shape_style *pptx_ct_dgm_style_label_get_style(const pptx_ct_dgm_style_label *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_style_label_get_ext_lst(const pptx_ct_dgm_style_label *const obj);
pptx_string pptx_ct_dgm_style_label_get_name(const pptx_ct_dgm_style_label *const obj);
int32_t pptx_ct_dgm_style_label_get_index(pptx_ct_dgm_style_label *obj);

#endif /* __PPTX_CT_DGM_STYLE_LABEL_H__ */

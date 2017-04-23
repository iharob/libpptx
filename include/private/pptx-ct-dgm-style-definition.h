#ifndef __PPTX_CT_DGM_STYLE_DEFINITION_H__
#define __PPTX_CT_DGM_STYLE_DEFINITION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_sdname_s pptx_ct_dgm_sdname;
typedef struct pptx_ct_dgm_sddescription_s pptx_ct_dgm_sddescription;
typedef struct pptx_ct_dgm_sdcategories_s pptx_ct_dgm_sdcategories;
typedef struct pptx_ct_a_scene_3d_s pptx_ct_a_scene_3d;
typedef struct pptx_ct_dgm_style_label_s pptx_ct_dgm_style_label;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_dgm_style_definition_s pptx_ct_dgm_style_definition;
pptx_ct_dgm_style_definition *pptx_ct_dgm_style_definition_new(xmlNode *node);
void pptx_ct_dgm_style_definition_free(pptx_ct_dgm_style_definition *obj);
pptx_ct_dgm_sdname **pptx_ct_dgm_style_definition_get_title(const pptx_ct_dgm_style_definition *const obj);
pptx_ct_dgm_sddescription **pptx_ct_dgm_style_definition_get_desc(const pptx_ct_dgm_style_definition *const obj);
pptx_ct_dgm_sdcategories *pptx_ct_dgm_style_definition_get_cat_lst(const pptx_ct_dgm_style_definition *const obj);
pptx_ct_a_scene_3d *pptx_ct_dgm_style_definition_get_scene3d(const pptx_ct_dgm_style_definition *const obj);
pptx_ct_dgm_style_label **pptx_ct_dgm_style_definition_get_style_lbl(const pptx_ct_dgm_style_definition *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_style_definition_get_ext_lst(const pptx_ct_dgm_style_definition *const obj);
pptx_string pptx_ct_dgm_style_definition_get_unique_id(const pptx_ct_dgm_style_definition *const obj);
pptx_string pptx_ct_dgm_style_definition_get_min_ver(const pptx_ct_dgm_style_definition *const obj);
int32_t pptx_ct_dgm_style_definition_get_index(pptx_ct_dgm_style_definition *obj);

#endif /* __PPTX_CT_DGM_STYLE_DEFINITION_H__ */

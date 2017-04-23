#ifndef __PPTX_CT_DGM_COLOR_TRANSFORM_H__
#define __PPTX_CT_DGM_COLOR_TRANSFORM_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_ctname_s pptx_ct_dgm_ctname;
typedef struct pptx_ct_dgm_ctdescription_s pptx_ct_dgm_ctdescription;
typedef struct pptx_ct_dgm_ctcategories_s pptx_ct_dgm_ctcategories;
typedef struct pptx_ct_dgm_ctstyle_label_s pptx_ct_dgm_ctstyle_label;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_dgm_color_transform_s pptx_ct_dgm_color_transform;
pptx_ct_dgm_color_transform *pptx_ct_dgm_color_transform_new(xmlNode *node);
void pptx_ct_dgm_color_transform_free(pptx_ct_dgm_color_transform *obj);
pptx_ct_dgm_ctname **pptx_ct_dgm_color_transform_get_title(const pptx_ct_dgm_color_transform *const obj);
pptx_ct_dgm_ctdescription **pptx_ct_dgm_color_transform_get_desc(const pptx_ct_dgm_color_transform *const obj);
pptx_ct_dgm_ctcategories *pptx_ct_dgm_color_transform_get_cat_lst(const pptx_ct_dgm_color_transform *const obj);
pptx_ct_dgm_ctstyle_label **pptx_ct_dgm_color_transform_get_style_lbl(const pptx_ct_dgm_color_transform *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_color_transform_get_ext_lst(const pptx_ct_dgm_color_transform *const obj);
pptx_string pptx_ct_dgm_color_transform_get_unique_id(const pptx_ct_dgm_color_transform *const obj);
pptx_string pptx_ct_dgm_color_transform_get_min_ver(const pptx_ct_dgm_color_transform *const obj);
int32_t pptx_ct_dgm_color_transform_get_index(pptx_ct_dgm_color_transform *obj);

#endif /* __PPTX_CT_DGM_COLOR_TRANSFORM_H__ */

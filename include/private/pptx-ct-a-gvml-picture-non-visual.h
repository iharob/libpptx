#ifndef __PPTX_CT_A_GVML_PICTURE_NON_VISUAL_H__
#define __PPTX_CT_A_GVML_PICTURE_NON_VISUAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_non_visual_drawing_props_s pptx_ct_a_non_visual_drawing_props;
typedef struct pptx_ct_a_non_visual_picture_properties_s pptx_ct_a_non_visual_picture_properties;

typedef struct pptx_ct_a_gvml_picture_non_visual_s pptx_ct_a_gvml_picture_non_visual;
pptx_ct_a_gvml_picture_non_visual *pptx_ct_a_gvml_picture_non_visual_new(xmlNode *node);
void pptx_ct_a_gvml_picture_non_visual_free(pptx_ct_a_gvml_picture_non_visual *obj);
pptx_ct_a_non_visual_drawing_props *pptx_ct_a_gvml_picture_non_visual_get_c_nv_pr(const pptx_ct_a_gvml_picture_non_visual *const obj);
pptx_ct_a_non_visual_picture_properties *pptx_ct_a_gvml_picture_non_visual_get_c_nv_pic_pr(const pptx_ct_a_gvml_picture_non_visual *const obj);
int32_t pptx_ct_a_gvml_picture_non_visual_get_index(pptx_ct_a_gvml_picture_non_visual *obj);

#endif /* __PPTX_CT_A_GVML_PICTURE_NON_VISUAL_H__ */

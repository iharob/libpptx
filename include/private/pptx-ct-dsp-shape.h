#ifndef __PPTX_CT_DSP_SHAPE_H__
#define __PPTX_CT_DSP_SHAPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dsp_shape_non_visual_s pptx_ct_dsp_shape_non_visual;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_shape_style_s pptx_ct_a_shape_style;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_transform_2d_s pptx_ct_a_transform_2d;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_dsp_shape_s pptx_ct_dsp_shape;
pptx_ct_dsp_shape *pptx_ct_dsp_shape_new(xmlNode *node);
void pptx_ct_dsp_shape_free(pptx_ct_dsp_shape *obj);
pptx_ct_dsp_shape_non_visual *pptx_ct_dsp_shape_get_nv_sp_pr(const pptx_ct_dsp_shape *const obj);
pptx_ct_a_shape_properties *pptx_ct_dsp_shape_get_sp_pr(const pptx_ct_dsp_shape *const obj);
pptx_ct_a_shape_style *pptx_ct_dsp_shape_get_style(const pptx_ct_dsp_shape *const obj);
pptx_ct_a_text_body *pptx_ct_dsp_shape_get_tx_body(const pptx_ct_dsp_shape *const obj);
pptx_ct_a_transform_2d *pptx_ct_dsp_shape_get_tx_xfrm(const pptx_ct_dsp_shape *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dsp_shape_get_ext_lst(const pptx_ct_dsp_shape *const obj);
pptx_string pptx_ct_dsp_shape_get_model_id(const pptx_ct_dsp_shape *const obj);
int32_t pptx_ct_dsp_shape_get_index(pptx_ct_dsp_shape *obj);

#endif /* __PPTX_CT_DSP_SHAPE_H__ */

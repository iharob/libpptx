#ifndef __PPTX_CT_DSP_DRAWING_H__
#define __PPTX_CT_DSP_DRAWING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dsp_group_shape_s pptx_ct_dsp_group_shape;

typedef struct pptx_ct_dsp_drawing_s pptx_ct_dsp_drawing;
pptx_ct_dsp_drawing *pptx_ct_dsp_drawing_new(xmlNode *node);
void pptx_ct_dsp_drawing_free(pptx_ct_dsp_drawing *obj);
pptx_ct_dsp_group_shape *pptx_ct_dsp_drawing_get_sp_tree(const pptx_ct_dsp_drawing *const obj);
int32_t pptx_ct_dsp_drawing_get_index(pptx_ct_dsp_drawing *obj);

#endif /* __PPTX_CT_DSP_DRAWING_H__ */

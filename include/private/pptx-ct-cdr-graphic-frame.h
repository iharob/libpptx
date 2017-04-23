#ifndef __PPTX_CT_CDR_GRAPHIC_FRAME_H__
#define __PPTX_CT_CDR_GRAPHIC_FRAME_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_cdr_graphic_frame_non_visual_s pptx_ct_cdr_graphic_frame_non_visual;
typedef struct pptx_ct_a_transform_2d_s pptx_ct_a_transform_2d;
typedef struct pptx_ct_a_graphical_object_s pptx_ct_a_graphical_object;

typedef struct pptx_ct_cdr_graphic_frame_s pptx_ct_cdr_graphic_frame;
pptx_ct_cdr_graphic_frame *pptx_ct_cdr_graphic_frame_new(xmlNode *node);
void pptx_ct_cdr_graphic_frame_free(pptx_ct_cdr_graphic_frame *obj);
pptx_ct_cdr_graphic_frame_non_visual *pptx_ct_cdr_graphic_frame_get_nv_graphic_frame_pr(const pptx_ct_cdr_graphic_frame *const obj);
pptx_ct_a_transform_2d *pptx_ct_cdr_graphic_frame_get_xfrm(const pptx_ct_cdr_graphic_frame *const obj);
pptx_ct_a_graphical_object *pptx_ct_cdr_graphic_frame_get_graphic(const pptx_ct_cdr_graphic_frame *const obj);
pptx_string pptx_ct_cdr_graphic_frame_get_macro(const pptx_ct_cdr_graphic_frame *const obj);
pptx_bool pptx_ct_cdr_graphic_frame_get_f_published(const pptx_ct_cdr_graphic_frame *const obj);
int32_t pptx_ct_cdr_graphic_frame_get_index(pptx_ct_cdr_graphic_frame *obj);

#endif /* __PPTX_CT_CDR_GRAPHIC_FRAME_H__ */

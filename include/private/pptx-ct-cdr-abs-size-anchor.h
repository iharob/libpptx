#ifndef __PPTX_CT_CDR_ABS_SIZE_ANCHOR_H__
#define __PPTX_CT_CDR_ABS_SIZE_ANCHOR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_cdr_marker_s pptx_ct_cdr_marker;
typedef struct pptx_ct_a_positive_size_2d_s pptx_ct_a_positive_size_2d;
typedef struct pptx_ct_cdr_shape_s pptx_ct_cdr_shape;
typedef struct pptx_ct_cdr_group_shape_s pptx_ct_cdr_group_shape;
typedef struct pptx_ct_cdr_graphic_frame_s pptx_ct_cdr_graphic_frame;
typedef struct pptx_ct_cdr_connector_s pptx_ct_cdr_connector;
typedef struct pptx_ct_cdr_picture_s pptx_ct_cdr_picture;

typedef struct pptx_ct_cdr_abs_size_anchor_s pptx_ct_cdr_abs_size_anchor;
pptx_ct_cdr_abs_size_anchor *pptx_ct_cdr_abs_size_anchor_new(xmlNode *node);
void pptx_ct_cdr_abs_size_anchor_free(pptx_ct_cdr_abs_size_anchor *obj);
pptx_ct_cdr_marker *pptx_ct_cdr_abs_size_anchor_get_from(const pptx_ct_cdr_abs_size_anchor *const obj);
pptx_ct_a_positive_size_2d *pptx_ct_cdr_abs_size_anchor_get_ext(const pptx_ct_cdr_abs_size_anchor *const obj);
pptx_ct_cdr_shape *pptx_ct_cdr_abs_size_anchor_get_sp(const pptx_ct_cdr_abs_size_anchor *const obj);
pptx_ct_cdr_group_shape *pptx_ct_cdr_abs_size_anchor_get_grp_sp(const pptx_ct_cdr_abs_size_anchor *const obj);
pptx_ct_cdr_graphic_frame *pptx_ct_cdr_abs_size_anchor_get_graphic_frame(const pptx_ct_cdr_abs_size_anchor *const obj);
pptx_ct_cdr_connector *pptx_ct_cdr_abs_size_anchor_get_cxn_sp(const pptx_ct_cdr_abs_size_anchor *const obj);
pptx_ct_cdr_picture *pptx_ct_cdr_abs_size_anchor_get_pic(const pptx_ct_cdr_abs_size_anchor *const obj);
int32_t pptx_ct_cdr_abs_size_anchor_get_index(pptx_ct_cdr_abs_size_anchor *obj);

#endif /* __PPTX_CT_CDR_ABS_SIZE_ANCHOR_H__ */

#ifndef __PPTX_CT_A_GVML_USE_SHAPE_RECTANGLE_H__
#define __PPTX_CT_A_GVML_USE_SHAPE_RECTANGLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_gvml_use_shape_rectangle_s pptx_ct_a_gvml_use_shape_rectangle;
pptx_ct_a_gvml_use_shape_rectangle *pptx_ct_a_gvml_use_shape_rectangle_new(xmlNode *node);
void pptx_ct_a_gvml_use_shape_rectangle_free(pptx_ct_a_gvml_use_shape_rectangle *obj);
int32_t pptx_ct_a_gvml_use_shape_rectangle_get_index(pptx_ct_a_gvml_use_shape_rectangle *obj);

#endif /* __PPTX_CT_A_GVML_USE_SHAPE_RECTANGLE_H__ */

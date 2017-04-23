#ifndef __PPTX_CT_A_SHAPE_H__
#define __PPTX_CT_A_SHAPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_shape_text_enum pptx_st_shape_text_enum;

typedef struct pptx_ct_a_shape_s pptx_ct_a_shape;
pptx_ct_a_shape *pptx_ct_a_shape_new(xmlNode *node);
void pptx_ct_a_shape_free(pptx_ct_a_shape *obj);
pptx_st_shape_text_enum pptx_ct_a_shape_get_val(const pptx_ct_a_shape *const obj);
int32_t pptx_ct_a_shape_get_index(pptx_ct_a_shape *obj);

#endif /* __PPTX_CT_A_SHAPE_H__ */

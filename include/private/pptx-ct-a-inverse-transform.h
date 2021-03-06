#ifndef __PPTX_CT_A_INVERSE_TRANSFORM_H__
#define __PPTX_CT_A_INVERSE_TRANSFORM_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_inverse_transform_s pptx_ct_a_inverse_transform;
pptx_ct_a_inverse_transform *pptx_ct_a_inverse_transform_new(xmlNode *node);
void pptx_ct_a_inverse_transform_free(pptx_ct_a_inverse_transform *obj);
int32_t pptx_ct_a_inverse_transform_get_index(pptx_ct_a_inverse_transform *obj);

#endif /* __PPTX_CT_A_INVERSE_TRANSFORM_H__ */

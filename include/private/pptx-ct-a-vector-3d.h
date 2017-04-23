#ifndef __PPTX_CT_A_VECTOR_3D_H__
#define __PPTX_CT_A_VECTOR_3D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_vector_3d_s pptx_ct_a_vector_3d;
pptx_ct_a_vector_3d *pptx_ct_a_vector_3d_new(xmlNode *node);
void pptx_ct_a_vector_3d_free(pptx_ct_a_vector_3d *obj);
pptx_string pptx_ct_a_vector_3d_get_dx(const pptx_ct_a_vector_3d *const obj);
pptx_string pptx_ct_a_vector_3d_get_dy(const pptx_ct_a_vector_3d *const obj);
pptx_string pptx_ct_a_vector_3d_get_dz(const pptx_ct_a_vector_3d *const obj);
int32_t pptx_ct_a_vector_3d_get_index(pptx_ct_a_vector_3d *obj);

#endif /* __PPTX_CT_A_VECTOR_3D_H__ */

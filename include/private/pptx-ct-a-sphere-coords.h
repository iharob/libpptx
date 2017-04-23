#ifndef __PPTX_CT_A_SPHERE_COORDS_H__
#define __PPTX_CT_A_SPHERE_COORDS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_sphere_coords_s pptx_ct_a_sphere_coords;
pptx_ct_a_sphere_coords *pptx_ct_a_sphere_coords_new(xmlNode *node);
void pptx_ct_a_sphere_coords_free(pptx_ct_a_sphere_coords *obj);
pptx_int pptx_ct_a_sphere_coords_get_lat(const pptx_ct_a_sphere_coords *const obj);
pptx_int pptx_ct_a_sphere_coords_get_lon(const pptx_ct_a_sphere_coords *const obj);
pptx_int pptx_ct_a_sphere_coords_get_rev(const pptx_ct_a_sphere_coords *const obj);
int32_t pptx_ct_a_sphere_coords_get_index(pptx_ct_a_sphere_coords *obj);

#endif /* __PPTX_CT_A_SPHERE_COORDS_H__ */

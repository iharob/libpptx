#ifndef __PPTX_CT_A_BACKDROP_H__
#define __PPTX_CT_A_BACKDROP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_point_3d_s pptx_ct_a_point_3d;
typedef struct pptx_ct_a_vector_3d_s pptx_ct_a_vector_3d;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_backdrop_s pptx_ct_a_backdrop;
pptx_ct_a_backdrop *pptx_ct_a_backdrop_new(xmlNode *node);
void pptx_ct_a_backdrop_free(pptx_ct_a_backdrop *obj);
pptx_ct_a_point_3d *pptx_ct_a_backdrop_get_anchor(const pptx_ct_a_backdrop *const obj);
pptx_ct_a_vector_3d *pptx_ct_a_backdrop_get_norm(const pptx_ct_a_backdrop *const obj);
pptx_ct_a_vector_3d *pptx_ct_a_backdrop_get_up(const pptx_ct_a_backdrop *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_backdrop_get_ext_lst(const pptx_ct_a_backdrop *const obj);
int32_t pptx_ct_a_backdrop_get_index(pptx_ct_a_backdrop *obj);

#endif /* __PPTX_CT_A_BACKDROP_H__ */

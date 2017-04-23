#ifndef __PPTX_CT_A_SURFACE_H__
#define __PPTX_CT_A_SURFACE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_thickness_s pptx_ct_a_thickness;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_picture_options_s pptx_ct_a_picture_options;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_surface_s pptx_ct_a_surface;
pptx_ct_a_surface *pptx_ct_a_surface_new(xmlNode *node);
void pptx_ct_a_surface_free(pptx_ct_a_surface *obj);
pptx_ct_a_thickness *pptx_ct_a_surface_get_thickness(const pptx_ct_a_surface *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_surface_get_sp_pr(const pptx_ct_a_surface *const obj);
pptx_ct_a_picture_options *pptx_ct_a_surface_get_picture_options(const pptx_ct_a_surface *const obj);
pptx_ct_a_extension_list *pptx_ct_a_surface_get_ext_lst(const pptx_ct_a_surface *const obj);
int32_t pptx_ct_a_surface_get_index(pptx_ct_a_surface *obj);

#endif /* __PPTX_CT_A_SURFACE_H__ */

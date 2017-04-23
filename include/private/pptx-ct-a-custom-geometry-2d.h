#ifndef __PPTX_CT_A_CUSTOM_GEOMETRY_2D_H__
#define __PPTX_CT_A_CUSTOM_GEOMETRY_2D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_geom_guide_list_s pptx_ct_a_geom_guide_list;
typedef struct pptx_ct_a_adjust_handle_list_s pptx_ct_a_adjust_handle_list;
typedef struct pptx_ct_a_connection_site_list_s pptx_ct_a_connection_site_list;
typedef struct pptx_ct_a_geom_rect_s pptx_ct_a_geom_rect;
typedef struct pptx_ct_a_path_2dlist_s pptx_ct_a_path_2dlist;

typedef struct pptx_ct_a_custom_geometry_2d_s pptx_ct_a_custom_geometry_2d;
pptx_ct_a_custom_geometry_2d *pptx_ct_a_custom_geometry_2d_new(xmlNode *node);
void pptx_ct_a_custom_geometry_2d_free(pptx_ct_a_custom_geometry_2d *obj);
pptx_ct_a_geom_guide_list *pptx_ct_a_custom_geometry_2d_get_av_lst(const pptx_ct_a_custom_geometry_2d *const obj);
pptx_ct_a_geom_guide_list *pptx_ct_a_custom_geometry_2d_get_gd_lst(const pptx_ct_a_custom_geometry_2d *const obj);
pptx_ct_a_adjust_handle_list *pptx_ct_a_custom_geometry_2d_get_ah_lst(const pptx_ct_a_custom_geometry_2d *const obj);
pptx_ct_a_connection_site_list *pptx_ct_a_custom_geometry_2d_get_cxn_lst(const pptx_ct_a_custom_geometry_2d *const obj);
pptx_ct_a_geom_rect *pptx_ct_a_custom_geometry_2d_get_rect(const pptx_ct_a_custom_geometry_2d *const obj);
pptx_ct_a_path_2dlist *pptx_ct_a_custom_geometry_2d_get_path_lst(const pptx_ct_a_custom_geometry_2d *const obj);
int32_t pptx_ct_a_custom_geometry_2d_get_index(pptx_ct_a_custom_geometry_2d *obj);

#endif /* __PPTX_CT_A_CUSTOM_GEOMETRY_2D_H__ */

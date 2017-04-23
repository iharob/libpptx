#ifndef __PPTX_CT_A_SURFACE_3DCHART_H__
#define __PPTX_CT_A_SURFACE_3DCHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_surface_ser_s pptx_ct_a_surface_ser;
typedef struct pptx_ct_a_band_fmts_s pptx_ct_a_band_fmts;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_surface_3dchart_s pptx_ct_a_surface_3dchart;
pptx_ct_a_surface_3dchart *pptx_ct_a_surface_3dchart_new(xmlNode *node);
void pptx_ct_a_surface_3dchart_free(pptx_ct_a_surface_3dchart *obj);
pptx_bool pptx_ct_a_surface_3dchart_get_surface_chart_shared_wireframe(const pptx_ct_a_surface_3dchart *const obj);
pptx_ct_a_surface_ser **pptx_ct_a_surface_3dchart_get_surface_chart_shared_ser(const pptx_ct_a_surface_3dchart *const obj);
pptx_ct_a_band_fmts *pptx_ct_a_surface_3dchart_get_surface_chart_shared_band_fmts(const pptx_ct_a_surface_3dchart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_surface_3dchart_get_ext_lst(const pptx_ct_a_surface_3dchart *const obj);
int32_t pptx_ct_a_surface_3dchart_get_index(pptx_ct_a_surface_3dchart *obj);

#endif /* __PPTX_CT_A_SURFACE_3DCHART_H__ */

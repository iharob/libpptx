#ifndef __PPTX_CT_A_SURFACE_CHART_H__
#define __PPTX_CT_A_SURFACE_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_surface_ser_s pptx_ct_a_surface_ser;
typedef struct pptx_ct_a_band_fmts_s pptx_ct_a_band_fmts;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_surface_chart_s pptx_ct_a_surface_chart;
pptx_ct_a_surface_chart *pptx_ct_a_surface_chart_new(xmlNode *node);
void pptx_ct_a_surface_chart_free(pptx_ct_a_surface_chart *obj);
pptx_bool pptx_ct_a_surface_chart_get_surface_chart_shared_wireframe(const pptx_ct_a_surface_chart *const obj);
pptx_ct_a_surface_ser **pptx_ct_a_surface_chart_get_surface_chart_shared_ser(const pptx_ct_a_surface_chart *const obj);
pptx_ct_a_band_fmts *pptx_ct_a_surface_chart_get_surface_chart_shared_band_fmts(const pptx_ct_a_surface_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_surface_chart_get_ext_lst(const pptx_ct_a_surface_chart *const obj);
int32_t pptx_ct_a_surface_chart_get_index(pptx_ct_a_surface_chart *obj);

#endif /* __PPTX_CT_A_SURFACE_CHART_H__ */

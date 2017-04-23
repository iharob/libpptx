#ifndef __PPTX_CT_A_DOUGHNUT_CHART_H__
#define __PPTX_CT_A_DOUGHNUT_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_pie_ser_s pptx_ct_a_pie_ser;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_first_slice_ang_s pptx_ct_a_first_slice_ang;
typedef struct pptx_ct_a_hole_size_s pptx_ct_a_hole_size;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_doughnut_chart_s pptx_ct_a_doughnut_chart;
pptx_ct_a_doughnut_chart *pptx_ct_a_doughnut_chart_new(xmlNode *node);
void pptx_ct_a_doughnut_chart_free(pptx_ct_a_doughnut_chart *obj);
pptx_bool pptx_ct_a_doughnut_chart_get_pie_chart_shared_vary_colors(const pptx_ct_a_doughnut_chart *const obj);
pptx_ct_a_pie_ser **pptx_ct_a_doughnut_chart_get_pie_chart_shared_ser(const pptx_ct_a_doughnut_chart *const obj);
pptx_ct_a_dlbls *pptx_ct_a_doughnut_chart_get_pie_chart_shared_d_lbls(const pptx_ct_a_doughnut_chart *const obj);
pptx_ct_a_first_slice_ang *pptx_ct_a_doughnut_chart_get_first_slice_ang(const pptx_ct_a_doughnut_chart *const obj);
pptx_ct_a_hole_size *pptx_ct_a_doughnut_chart_get_hole_size(const pptx_ct_a_doughnut_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_doughnut_chart_get_ext_lst(const pptx_ct_a_doughnut_chart *const obj);
int32_t pptx_ct_a_doughnut_chart_get_index(pptx_ct_a_doughnut_chart *obj);

#endif /* __PPTX_CT_A_DOUGHNUT_CHART_H__ */

#ifndef __PPTX_CT_A_AREA_CHART_H__
#define __PPTX_CT_A_AREA_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_grouping_s pptx_ct_a_grouping;
typedef struct pptx_ct_a_area_ser_s pptx_ct_a_area_ser;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_chart_lines_s pptx_ct_a_chart_lines;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_area_chart_s pptx_ct_a_area_chart;
pptx_ct_a_area_chart *pptx_ct_a_area_chart_new(xmlNode *node);
void pptx_ct_a_area_chart_free(pptx_ct_a_area_chart *obj);
pptx_ct_a_grouping *pptx_ct_a_area_chart_get_area_chart_shared_grouping(const pptx_ct_a_area_chart *const obj);
pptx_bool pptx_ct_a_area_chart_get_area_chart_shared_vary_colors(const pptx_ct_a_area_chart *const obj);
pptx_ct_a_area_ser **pptx_ct_a_area_chart_get_area_chart_shared_ser(const pptx_ct_a_area_chart *const obj);
pptx_ct_a_dlbls *pptx_ct_a_area_chart_get_area_chart_shared_d_lbls(const pptx_ct_a_area_chart *const obj);
pptx_ct_a_chart_lines *pptx_ct_a_area_chart_get_area_chart_shared_drop_lines(const pptx_ct_a_area_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_area_chart_get_ext_lst(const pptx_ct_a_area_chart *const obj);
int32_t pptx_ct_a_area_chart_get_index(pptx_ct_a_area_chart *obj);

#endif /* __PPTX_CT_A_AREA_CHART_H__ */

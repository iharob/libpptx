#ifndef __PPTX_CT_A_RADAR_CHART_H__
#define __PPTX_CT_A_RADAR_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_radar_style_s pptx_ct_a_radar_style;
typedef struct pptx_ct_a_radar_ser_s pptx_ct_a_radar_ser;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_radar_chart_s pptx_ct_a_radar_chart;
pptx_ct_a_radar_chart *pptx_ct_a_radar_chart_new(xmlNode *node);
void pptx_ct_a_radar_chart_free(pptx_ct_a_radar_chart *obj);
pptx_ct_a_radar_style *pptx_ct_a_radar_chart_get_radar_style(const pptx_ct_a_radar_chart *const obj);
pptx_bool pptx_ct_a_radar_chart_get_vary_colors(const pptx_ct_a_radar_chart *const obj);
pptx_ct_a_radar_ser **pptx_ct_a_radar_chart_get_ser(const pptx_ct_a_radar_chart *const obj);
pptx_ct_a_dlbls *pptx_ct_a_radar_chart_get_d_lbls(const pptx_ct_a_radar_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_radar_chart_get_ext_lst(const pptx_ct_a_radar_chart *const obj);
int32_t pptx_ct_a_radar_chart_get_index(pptx_ct_a_radar_chart *obj);

#endif /* __PPTX_CT_A_RADAR_CHART_H__ */

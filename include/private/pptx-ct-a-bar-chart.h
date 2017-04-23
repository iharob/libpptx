#ifndef __PPTX_CT_A_BAR_CHART_H__
#define __PPTX_CT_A_BAR_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_bar_dir_s pptx_ct_a_bar_dir;
typedef struct pptx_ct_a_bar_grouping_s pptx_ct_a_bar_grouping;
typedef struct pptx_ct_a_bar_ser_s pptx_ct_a_bar_ser;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_gap_amount_s pptx_ct_a_gap_amount;
typedef struct pptx_ct_a_overlap_s pptx_ct_a_overlap;
typedef struct pptx_ct_a_chart_lines_s pptx_ct_a_chart_lines;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_bar_chart_s pptx_ct_a_bar_chart;
pptx_ct_a_bar_chart *pptx_ct_a_bar_chart_new(xmlNode *node);
void pptx_ct_a_bar_chart_free(pptx_ct_a_bar_chart *obj);
pptx_ct_a_bar_dir *pptx_ct_a_bar_chart_get_bar_chart_shared_bar_dir(const pptx_ct_a_bar_chart *const obj);
pptx_ct_a_bar_grouping *pptx_ct_a_bar_chart_get_bar_chart_shared_grouping(const pptx_ct_a_bar_chart *const obj);
pptx_bool pptx_ct_a_bar_chart_get_bar_chart_shared_vary_colors(const pptx_ct_a_bar_chart *const obj);
pptx_ct_a_bar_ser **pptx_ct_a_bar_chart_get_bar_chart_shared_ser(const pptx_ct_a_bar_chart *const obj);
pptx_ct_a_dlbls *pptx_ct_a_bar_chart_get_bar_chart_shared_d_lbls(const pptx_ct_a_bar_chart *const obj);
pptx_ct_a_gap_amount *pptx_ct_a_bar_chart_get_gap_width(const pptx_ct_a_bar_chart *const obj);
pptx_ct_a_overlap *pptx_ct_a_bar_chart_get_overlap(const pptx_ct_a_bar_chart *const obj);
pptx_ct_a_chart_lines **pptx_ct_a_bar_chart_get_ser_lines(const pptx_ct_a_bar_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_bar_chart_get_ext_lst(const pptx_ct_a_bar_chart *const obj);
int32_t pptx_ct_a_bar_chart_get_index(pptx_ct_a_bar_chart *obj);

#endif /* __PPTX_CT_A_BAR_CHART_H__ */

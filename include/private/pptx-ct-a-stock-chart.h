#ifndef __PPTX_CT_A_STOCK_CHART_H__
#define __PPTX_CT_A_STOCK_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_line_ser_s pptx_ct_a_line_ser;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_chart_lines_s pptx_ct_a_chart_lines;
typedef struct pptx_ct_a_up_down_bars_s pptx_ct_a_up_down_bars;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_stock_chart_s pptx_ct_a_stock_chart;
pptx_ct_a_stock_chart *pptx_ct_a_stock_chart_new(xmlNode *node);
void pptx_ct_a_stock_chart_free(pptx_ct_a_stock_chart *obj);
pptx_ct_a_line_ser **pptx_ct_a_stock_chart_get_ser(const pptx_ct_a_stock_chart *const obj);
pptx_ct_a_dlbls *pptx_ct_a_stock_chart_get_d_lbls(const pptx_ct_a_stock_chart *const obj);
pptx_ct_a_chart_lines *pptx_ct_a_stock_chart_get_drop_lines(const pptx_ct_a_stock_chart *const obj);
pptx_ct_a_chart_lines *pptx_ct_a_stock_chart_get_hi_low_lines(const pptx_ct_a_stock_chart *const obj);
pptx_ct_a_up_down_bars *pptx_ct_a_stock_chart_get_up_down_bars(const pptx_ct_a_stock_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_stock_chart_get_ext_lst(const pptx_ct_a_stock_chart *const obj);
int32_t pptx_ct_a_stock_chart_get_index(pptx_ct_a_stock_chart *obj);

#endif /* __PPTX_CT_A_STOCK_CHART_H__ */

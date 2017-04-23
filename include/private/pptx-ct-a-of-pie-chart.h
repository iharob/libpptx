#ifndef __PPTX_CT_A_OF_PIE_CHART_H__
#define __PPTX_CT_A_OF_PIE_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_of_pie_type_s pptx_ct_a_of_pie_type;
typedef struct pptx_ct_a_pie_ser_s pptx_ct_a_pie_ser;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_gap_amount_s pptx_ct_a_gap_amount;
typedef struct pptx_ct_a_split_type_s pptx_ct_a_split_type;
typedef struct pptx_ct_a_double_s pptx_ct_a_double;
typedef struct pptx_ct_a_cust_split_s pptx_ct_a_cust_split;
typedef struct pptx_ct_a_second_pie_size_s pptx_ct_a_second_pie_size;
typedef struct pptx_ct_a_chart_lines_s pptx_ct_a_chart_lines;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_of_pie_chart_s pptx_ct_a_of_pie_chart;
pptx_ct_a_of_pie_chart *pptx_ct_a_of_pie_chart_new(xmlNode *node);
void pptx_ct_a_of_pie_chart_free(pptx_ct_a_of_pie_chart *obj);
pptx_ct_a_of_pie_type *pptx_ct_a_of_pie_chart_get_of_pie_type(const pptx_ct_a_of_pie_chart *const obj);
pptx_bool pptx_ct_a_of_pie_chart_get_pie_chart_shared_vary_colors(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_pie_ser **pptx_ct_a_of_pie_chart_get_pie_chart_shared_ser(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_dlbls *pptx_ct_a_of_pie_chart_get_pie_chart_shared_d_lbls(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_gap_amount *pptx_ct_a_of_pie_chart_get_gap_width(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_split_type *pptx_ct_a_of_pie_chart_get_split_type(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_double *pptx_ct_a_of_pie_chart_get_split_pos(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_cust_split *pptx_ct_a_of_pie_chart_get_cust_split(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_second_pie_size *pptx_ct_a_of_pie_chart_get_second_pie_size(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_chart_lines **pptx_ct_a_of_pie_chart_get_ser_lines(const pptx_ct_a_of_pie_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_of_pie_chart_get_ext_lst(const pptx_ct_a_of_pie_chart *const obj);
int32_t pptx_ct_a_of_pie_chart_get_index(pptx_ct_a_of_pie_chart *obj);

#endif /* __PPTX_CT_A_OF_PIE_CHART_H__ */

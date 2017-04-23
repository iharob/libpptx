#ifndef __PPTX_CT_A_TRENDLINE_H__
#define __PPTX_CT_A_TRENDLINE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_trendline_type_s pptx_ct_a_trendline_type;
typedef struct pptx_ct_a_order_s pptx_ct_a_order;
typedef struct pptx_ct_a_period_s pptx_ct_a_period;
typedef struct pptx_ct_a_double_s pptx_ct_a_double;
typedef struct pptx_ct_a_trendline_lbl_s pptx_ct_a_trendline_lbl;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_trendline_s pptx_ct_a_trendline;
pptx_ct_a_trendline *pptx_ct_a_trendline_new(xmlNode *node);
void pptx_ct_a_trendline_free(pptx_ct_a_trendline *obj);
pptx_string pptx_ct_a_trendline_get_name(const pptx_ct_a_trendline *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_trendline_get_sp_pr(const pptx_ct_a_trendline *const obj);
pptx_ct_a_trendline_type *pptx_ct_a_trendline_get_trendline_type(const pptx_ct_a_trendline *const obj);
pptx_ct_a_order *pptx_ct_a_trendline_get_order(const pptx_ct_a_trendline *const obj);
pptx_ct_a_period *pptx_ct_a_trendline_get_period(const pptx_ct_a_trendline *const obj);
pptx_ct_a_double *pptx_ct_a_trendline_get_forward(const pptx_ct_a_trendline *const obj);
pptx_ct_a_double *pptx_ct_a_trendline_get_backward(const pptx_ct_a_trendline *const obj);
pptx_ct_a_double *pptx_ct_a_trendline_get_intercept(const pptx_ct_a_trendline *const obj);
pptx_bool pptx_ct_a_trendline_get_disp_rsqr(const pptx_ct_a_trendline *const obj);
pptx_bool pptx_ct_a_trendline_get_disp_eq(const pptx_ct_a_trendline *const obj);
pptx_ct_a_trendline_lbl *pptx_ct_a_trendline_get_trendline_lbl(const pptx_ct_a_trendline *const obj);
pptx_ct_a_extension_list *pptx_ct_a_trendline_get_ext_lst(const pptx_ct_a_trendline *const obj);
int32_t pptx_ct_a_trendline_get_index(pptx_ct_a_trendline *obj);

#endif /* __PPTX_CT_A_TRENDLINE_H__ */

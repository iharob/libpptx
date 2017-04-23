#ifndef __PPTX_CT_A_BUBBLE_CHART_H__
#define __PPTX_CT_A_BUBBLE_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_bubble_ser_s pptx_ct_a_bubble_ser;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_bubble_scale_s pptx_ct_a_bubble_scale;
typedef struct pptx_ct_a_size_represents_s pptx_ct_a_size_represents;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_bubble_chart_s pptx_ct_a_bubble_chart;
pptx_ct_a_bubble_chart *pptx_ct_a_bubble_chart_new(xmlNode *node);
void pptx_ct_a_bubble_chart_free(pptx_ct_a_bubble_chart *obj);
pptx_bool pptx_ct_a_bubble_chart_get_vary_colors(const pptx_ct_a_bubble_chart *const obj);
pptx_ct_a_bubble_ser **pptx_ct_a_bubble_chart_get_ser(const pptx_ct_a_bubble_chart *const obj);
pptx_ct_a_dlbls *pptx_ct_a_bubble_chart_get_d_lbls(const pptx_ct_a_bubble_chart *const obj);
pptx_bool pptx_ct_a_bubble_chart_get_bubble_3d(const pptx_ct_a_bubble_chart *const obj);
pptx_ct_a_bubble_scale *pptx_ct_a_bubble_chart_get_bubble_scale(const pptx_ct_a_bubble_chart *const obj);
pptx_bool pptx_ct_a_bubble_chart_get_show_neg_bubbles(const pptx_ct_a_bubble_chart *const obj);
pptx_ct_a_size_represents *pptx_ct_a_bubble_chart_get_size_represents(const pptx_ct_a_bubble_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_bubble_chart_get_ext_lst(const pptx_ct_a_bubble_chart *const obj);
int32_t pptx_ct_a_bubble_chart_get_index(pptx_ct_a_bubble_chart *obj);

#endif /* __PPTX_CT_A_BUBBLE_CHART_H__ */

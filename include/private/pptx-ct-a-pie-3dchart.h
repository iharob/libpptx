#ifndef __PPTX_CT_A_PIE_3DCHART_H__
#define __PPTX_CT_A_PIE_3DCHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_pie_ser_s pptx_ct_a_pie_ser;
typedef struct pptx_ct_a_dlbls_s pptx_ct_a_dlbls;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_pie_3dchart_s pptx_ct_a_pie_3dchart;
pptx_ct_a_pie_3dchart *pptx_ct_a_pie_3dchart_new(xmlNode *node);
void pptx_ct_a_pie_3dchart_free(pptx_ct_a_pie_3dchart *obj);
pptx_bool pptx_ct_a_pie_3dchart_get_pie_chart_shared_vary_colors(const pptx_ct_a_pie_3dchart *const obj);
pptx_ct_a_pie_ser **pptx_ct_a_pie_3dchart_get_pie_chart_shared_ser(const pptx_ct_a_pie_3dchart *const obj);
pptx_ct_a_dlbls *pptx_ct_a_pie_3dchart_get_pie_chart_shared_d_lbls(const pptx_ct_a_pie_3dchart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_pie_3dchart_get_ext_lst(const pptx_ct_a_pie_3dchart *const obj);
int32_t pptx_ct_a_pie_3dchart_get_index(pptx_ct_a_pie_3dchart *obj);

#endif /* __PPTX_CT_A_PIE_3DCHART_H__ */

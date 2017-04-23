#ifndef __PPTX_CT_DGM_ORG_CHART_H__
#define __PPTX_CT_DGM_ORG_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_org_chart_s pptx_ct_dgm_org_chart;
pptx_ct_dgm_org_chart *pptx_ct_dgm_org_chart_new(xmlNode *node);
void pptx_ct_dgm_org_chart_free(pptx_ct_dgm_org_chart *obj);
pptx_bool pptx_ct_dgm_org_chart_get_val(const pptx_ct_dgm_org_chart *const obj);
int32_t pptx_ct_dgm_org_chart_get_index(pptx_ct_dgm_org_chart *obj);

#endif /* __PPTX_CT_DGM_ORG_CHART_H__ */

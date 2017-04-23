#ifndef __PPTX_CT_DGM_ADJ_H__
#define __PPTX_CT_DGM_ADJ_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_adj_s pptx_ct_dgm_adj;
pptx_ct_dgm_adj *pptx_ct_dgm_adj_new(xmlNode *node);
void pptx_ct_dgm_adj_free(pptx_ct_dgm_adj *obj);
pptx_uint pptx_ct_dgm_adj_get_idx(const pptx_ct_dgm_adj *const obj);
pptx_double pptx_ct_dgm_adj_get_val(const pptx_ct_dgm_adj *const obj);
int32_t pptx_ct_dgm_adj_get_index(pptx_ct_dgm_adj *obj);

#endif /* __PPTX_CT_DGM_ADJ_H__ */

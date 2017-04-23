#ifndef __PPTX_CT_DGM_ADJ_LST_H__
#define __PPTX_CT_DGM_ADJ_LST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_adj_s pptx_ct_dgm_adj;

typedef struct pptx_ct_dgm_adj_lst_s pptx_ct_dgm_adj_lst;
pptx_ct_dgm_adj_lst *pptx_ct_dgm_adj_lst_new(xmlNode *node);
void pptx_ct_dgm_adj_lst_free(pptx_ct_dgm_adj_lst *obj);
pptx_ct_dgm_adj **pptx_ct_dgm_adj_lst_get_adj(const pptx_ct_dgm_adj_lst *const obj);
int32_t pptx_ct_dgm_adj_lst_get_index(pptx_ct_dgm_adj_lst *obj);

#endif /* __PPTX_CT_DGM_ADJ_LST_H__ */

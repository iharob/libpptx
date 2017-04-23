#ifndef __PPTX_CT_DGM_REL_IDS_H__
#define __PPTX_CT_DGM_REL_IDS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_rel_ids_s pptx_ct_dgm_rel_ids;
pptx_ct_dgm_rel_ids *pptx_ct_dgm_rel_ids_new(xmlNode *node);
void pptx_ct_dgm_rel_ids_free(pptx_ct_dgm_rel_ids *obj);
pptx_string pptx_ct_dgm_rel_ids_get_dm(const pptx_ct_dgm_rel_ids *const obj);
pptx_string pptx_ct_dgm_rel_ids_get_lo(const pptx_ct_dgm_rel_ids *const obj);
pptx_string pptx_ct_dgm_rel_ids_get_qs(const pptx_ct_dgm_rel_ids *const obj);
pptx_string pptx_ct_dgm_rel_ids_get_cs(const pptx_ct_dgm_rel_ids *const obj);
int32_t pptx_ct_dgm_rel_ids_get_index(pptx_ct_dgm_rel_ids *obj);

#endif /* __PPTX_CT_DGM_REL_IDS_H__ */

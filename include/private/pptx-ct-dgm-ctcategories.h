#ifndef __PPTX_CT_DGM_CTCATEGORIES_H__
#define __PPTX_CT_DGM_CTCATEGORIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_ctcategory_s pptx_ct_dgm_ctcategory;

typedef struct pptx_ct_dgm_ctcategories_s pptx_ct_dgm_ctcategories;
pptx_ct_dgm_ctcategories *pptx_ct_dgm_ctcategories_new(xmlNode *node);
void pptx_ct_dgm_ctcategories_free(pptx_ct_dgm_ctcategories *obj);
pptx_ct_dgm_ctcategory **pptx_ct_dgm_ctcategories_get_cat(const pptx_ct_dgm_ctcategories *const obj);
int32_t pptx_ct_dgm_ctcategories_get_index(pptx_ct_dgm_ctcategories *obj);

#endif /* __PPTX_CT_DGM_CTCATEGORIES_H__ */

#ifndef __PPTX_CT_DGM_SDCATEGORIES_H__
#define __PPTX_CT_DGM_SDCATEGORIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_sdcategory_s pptx_ct_dgm_sdcategory;

typedef struct pptx_ct_dgm_sdcategories_s pptx_ct_dgm_sdcategories;
pptx_ct_dgm_sdcategories *pptx_ct_dgm_sdcategories_new(xmlNode *node);
void pptx_ct_dgm_sdcategories_free(pptx_ct_dgm_sdcategories *obj);
pptx_ct_dgm_sdcategory **pptx_ct_dgm_sdcategories_get_cat(const pptx_ct_dgm_sdcategories *const obj);
int32_t pptx_ct_dgm_sdcategories_get_index(pptx_ct_dgm_sdcategories *obj);

#endif /* __PPTX_CT_DGM_SDCATEGORIES_H__ */

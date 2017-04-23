#ifndef __PPTX_CT_DGM_SDCATEGORY_H__
#define __PPTX_CT_DGM_SDCATEGORY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_sdcategory_s pptx_ct_dgm_sdcategory;
pptx_ct_dgm_sdcategory *pptx_ct_dgm_sdcategory_new(xmlNode *node);
void pptx_ct_dgm_sdcategory_free(pptx_ct_dgm_sdcategory *obj);
pptx_string pptx_ct_dgm_sdcategory_get_type(const pptx_ct_dgm_sdcategory *const obj);
pptx_uint pptx_ct_dgm_sdcategory_get_pri(const pptx_ct_dgm_sdcategory *const obj);
int32_t pptx_ct_dgm_sdcategory_get_index(pptx_ct_dgm_sdcategory *obj);

#endif /* __PPTX_CT_DGM_SDCATEGORY_H__ */

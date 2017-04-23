#ifndef __PPTX_CT_DGM_CTCATEGORY_H__
#define __PPTX_CT_DGM_CTCATEGORY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_ctcategory_s pptx_ct_dgm_ctcategory;
pptx_ct_dgm_ctcategory *pptx_ct_dgm_ctcategory_new(xmlNode *node);
void pptx_ct_dgm_ctcategory_free(pptx_ct_dgm_ctcategory *obj);
pptx_string pptx_ct_dgm_ctcategory_get_type(const pptx_ct_dgm_ctcategory *const obj);
pptx_uint pptx_ct_dgm_ctcategory_get_pri(const pptx_ct_dgm_ctcategory *const obj);
int32_t pptx_ct_dgm_ctcategory_get_index(pptx_ct_dgm_ctcategory *obj);

#endif /* __PPTX_CT_DGM_CTCATEGORY_H__ */

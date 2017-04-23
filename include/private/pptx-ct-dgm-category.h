#ifndef __PPTX_CT_DGM_CATEGORY_H__
#define __PPTX_CT_DGM_CATEGORY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_category_s pptx_ct_dgm_category;
pptx_ct_dgm_category *pptx_ct_dgm_category_new(xmlNode *node);
void pptx_ct_dgm_category_free(pptx_ct_dgm_category *obj);
pptx_string pptx_ct_dgm_category_get_type(const pptx_ct_dgm_category *const obj);
pptx_uint pptx_ct_dgm_category_get_pri(const pptx_ct_dgm_category *const obj);
int32_t pptx_ct_dgm_category_get_index(pptx_ct_dgm_category *obj);

#endif /* __PPTX_CT_DGM_CATEGORY_H__ */

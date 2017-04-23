#ifndef __PPTX_CT_DGM_CATEGORIES_H__
#define __PPTX_CT_DGM_CATEGORIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_category_s pptx_ct_dgm_category;

typedef struct pptx_ct_dgm_categories_s pptx_ct_dgm_categories;
pptx_ct_dgm_categories *pptx_ct_dgm_categories_new(xmlNode *node);
void pptx_ct_dgm_categories_free(pptx_ct_dgm_categories *obj);
pptx_ct_dgm_category **pptx_ct_dgm_categories_get_cat(const pptx_ct_dgm_categories *const obj);
int32_t pptx_ct_dgm_categories_get_index(pptx_ct_dgm_categories *obj);

#endif /* __PPTX_CT_DGM_CATEGORIES_H__ */

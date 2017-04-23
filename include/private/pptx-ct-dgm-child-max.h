#ifndef __PPTX_CT_DGM_CHILD_MAX_H__
#define __PPTX_CT_DGM_CHILD_MAX_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_child_max_s pptx_ct_dgm_child_max;
pptx_ct_dgm_child_max *pptx_ct_dgm_child_max_new(xmlNode *node);
void pptx_ct_dgm_child_max_free(pptx_ct_dgm_child_max *obj);
pptx_int pptx_ct_dgm_child_max_get_val(const pptx_ct_dgm_child_max *const obj);
int32_t pptx_ct_dgm_child_max_get_index(pptx_ct_dgm_child_max *obj);

#endif /* __PPTX_CT_DGM_CHILD_MAX_H__ */

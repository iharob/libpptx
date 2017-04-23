#ifndef __PPTX_CT_DGM_CHILD_PREF_H__
#define __PPTX_CT_DGM_CHILD_PREF_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_child_pref_s pptx_ct_dgm_child_pref;
pptx_ct_dgm_child_pref *pptx_ct_dgm_child_pref_new(xmlNode *node);
void pptx_ct_dgm_child_pref_free(pptx_ct_dgm_child_pref *obj);
pptx_int pptx_ct_dgm_child_pref_get_val(const pptx_ct_dgm_child_pref *const obj);
int32_t pptx_ct_dgm_child_pref_get_index(pptx_ct_dgm_child_pref *obj);

#endif /* __PPTX_CT_DGM_CHILD_PREF_H__ */

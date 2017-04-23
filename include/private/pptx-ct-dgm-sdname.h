#ifndef __PPTX_CT_DGM_SDNAME_H__
#define __PPTX_CT_DGM_SDNAME_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_sdname_s pptx_ct_dgm_sdname;
pptx_ct_dgm_sdname *pptx_ct_dgm_sdname_new(xmlNode *node);
void pptx_ct_dgm_sdname_free(pptx_ct_dgm_sdname *obj);
pptx_string pptx_ct_dgm_sdname_get_lang(const pptx_ct_dgm_sdname *const obj);
pptx_string pptx_ct_dgm_sdname_get_val(const pptx_ct_dgm_sdname *const obj);
int32_t pptx_ct_dgm_sdname_get_index(pptx_ct_dgm_sdname *obj);

#endif /* __PPTX_CT_DGM_SDNAME_H__ */

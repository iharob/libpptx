#ifndef __PPTX_CT_DGM_DESCRIPTION_H__
#define __PPTX_CT_DGM_DESCRIPTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_description_s pptx_ct_dgm_description;
pptx_ct_dgm_description *pptx_ct_dgm_description_new(xmlNode *node);
void pptx_ct_dgm_description_free(pptx_ct_dgm_description *obj);
pptx_string pptx_ct_dgm_description_get_lang(const pptx_ct_dgm_description *const obj);
pptx_string pptx_ct_dgm_description_get_val(const pptx_ct_dgm_description *const obj);
int32_t pptx_ct_dgm_description_get_index(pptx_ct_dgm_description *obj);

#endif /* __PPTX_CT_DGM_DESCRIPTION_H__ */

#ifndef __PPTX_CT_DGM_CTDESCRIPTION_H__
#define __PPTX_CT_DGM_CTDESCRIPTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_ctdescription_s pptx_ct_dgm_ctdescription;
pptx_ct_dgm_ctdescription *pptx_ct_dgm_ctdescription_new(xmlNode *node);
void pptx_ct_dgm_ctdescription_free(pptx_ct_dgm_ctdescription *obj);
pptx_string pptx_ct_dgm_ctdescription_get_lang(const pptx_ct_dgm_ctdescription *const obj);
pptx_string pptx_ct_dgm_ctdescription_get_val(const pptx_ct_dgm_ctdescription *const obj);
int32_t pptx_ct_dgm_ctdescription_get_index(pptx_ct_dgm_ctdescription *obj);

#endif /* __PPTX_CT_DGM_CTDESCRIPTION_H__ */

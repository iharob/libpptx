#ifndef __PPTX_CT_DGM_SDDESCRIPTION_H__
#define __PPTX_CT_DGM_SDDESCRIPTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_sddescription_s pptx_ct_dgm_sddescription;
pptx_ct_dgm_sddescription *pptx_ct_dgm_sddescription_new(xmlNode *node);
void pptx_ct_dgm_sddescription_free(pptx_ct_dgm_sddescription *obj);
pptx_string pptx_ct_dgm_sddescription_get_lang(const pptx_ct_dgm_sddescription *const obj);
pptx_string pptx_ct_dgm_sddescription_get_val(const pptx_ct_dgm_sddescription *const obj);
int32_t pptx_ct_dgm_sddescription_get_index(pptx_ct_dgm_sddescription *obj);

#endif /* __PPTX_CT_DGM_SDDESCRIPTION_H__ */

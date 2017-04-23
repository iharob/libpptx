#ifndef __PPTX_CT_DGM_NAME_H__
#define __PPTX_CT_DGM_NAME_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_name_s pptx_ct_dgm_name;
pptx_ct_dgm_name *pptx_ct_dgm_name_new(xmlNode *node);
void pptx_ct_dgm_name_free(pptx_ct_dgm_name *obj);
pptx_string pptx_ct_dgm_name_get_lang(const pptx_ct_dgm_name *const obj);
pptx_string pptx_ct_dgm_name_get_val(const pptx_ct_dgm_name *const obj);
int32_t pptx_ct_dgm_name_get_index(pptx_ct_dgm_name *obj);

#endif /* __PPTX_CT_DGM_NAME_H__ */

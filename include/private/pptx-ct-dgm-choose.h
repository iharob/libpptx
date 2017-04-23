#ifndef __PPTX_CT_DGM_CHOOSE_H__
#define __PPTX_CT_DGM_CHOOSE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_when_s pptx_ct_dgm_when;
typedef struct pptx_ct_dgm_otherwise_s pptx_ct_dgm_otherwise;

typedef struct pptx_ct_dgm_choose_s pptx_ct_dgm_choose;
pptx_ct_dgm_choose *pptx_ct_dgm_choose_new(xmlNode *node);
void pptx_ct_dgm_choose_free(pptx_ct_dgm_choose *obj);
pptx_ct_dgm_when **pptx_ct_dgm_choose_get__if(const pptx_ct_dgm_choose *const obj);
pptx_ct_dgm_otherwise *pptx_ct_dgm_choose_get__else(const pptx_ct_dgm_choose *const obj);
pptx_string pptx_ct_dgm_choose_get_name(const pptx_ct_dgm_choose *const obj);
int32_t pptx_ct_dgm_choose_get_index(pptx_ct_dgm_choose *obj);

#endif /* __PPTX_CT_DGM_CHOOSE_H__ */

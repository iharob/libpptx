#ifndef __PPTX_CT_DGM_BULLET_ENABLED_H__
#define __PPTX_CT_DGM_BULLET_ENABLED_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dgm_bullet_enabled_s pptx_ct_dgm_bullet_enabled;
pptx_ct_dgm_bullet_enabled *pptx_ct_dgm_bullet_enabled_new(xmlNode *node);
void pptx_ct_dgm_bullet_enabled_free(pptx_ct_dgm_bullet_enabled *obj);
pptx_bool pptx_ct_dgm_bullet_enabled_get_val(const pptx_ct_dgm_bullet_enabled *const obj);
int32_t pptx_ct_dgm_bullet_enabled_get_index(pptx_ct_dgm_bullet_enabled *obj);

#endif /* __PPTX_CT_DGM_BULLET_ENABLED_H__ */

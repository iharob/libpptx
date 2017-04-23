#ifndef __PPTX_CT_DGM_DIRECTION_H__
#define __PPTX_CT_DGM_DIRECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_direction_token_enum pptx_st_direction_token_enum;

typedef struct pptx_ct_dgm_direction_s pptx_ct_dgm_direction;
pptx_ct_dgm_direction *pptx_ct_dgm_direction_new(xmlNode *node);
void pptx_ct_dgm_direction_free(pptx_ct_dgm_direction *obj);
pptx_st_direction_token_enum pptx_ct_dgm_direction_get_val(const pptx_ct_dgm_direction *const obj);
int32_t pptx_ct_dgm_direction_get_index(pptx_ct_dgm_direction *obj);

#endif /* __PPTX_CT_DGM_DIRECTION_H__ */

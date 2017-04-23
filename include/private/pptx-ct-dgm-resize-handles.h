#ifndef __PPTX_CT_DGM_RESIZE_HANDLES_H__
#define __PPTX_CT_DGM_RESIZE_HANDLES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_resize_handles_str_token_enum pptx_st_resize_handles_str_token_enum;

typedef struct pptx_ct_dgm_resize_handles_s pptx_ct_dgm_resize_handles;
pptx_ct_dgm_resize_handles *pptx_ct_dgm_resize_handles_new(xmlNode *node);
void pptx_ct_dgm_resize_handles_free(pptx_ct_dgm_resize_handles *obj);
pptx_st_resize_handles_str_token_enum pptx_ct_dgm_resize_handles_get_val(const pptx_ct_dgm_resize_handles *const obj);
int32_t pptx_ct_dgm_resize_handles_get_index(pptx_ct_dgm_resize_handles *obj);

#endif /* __PPTX_CT_DGM_RESIZE_HANDLES_H__ */

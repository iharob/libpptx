#ifndef __PPTX_CT_DGM_PARAMETER_H__
#define __PPTX_CT_DGM_PARAMETER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_parameter_id_token_enum pptx_st_parameter_id_token_enum;

typedef struct pptx_ct_dgm_parameter_s pptx_ct_dgm_parameter;
pptx_ct_dgm_parameter *pptx_ct_dgm_parameter_new(xmlNode *node);
void pptx_ct_dgm_parameter_free(pptx_ct_dgm_parameter *obj);
pptx_st_parameter_id_token_enum pptx_ct_dgm_parameter_get_type(const pptx_ct_dgm_parameter *const obj);
pptx_string pptx_ct_dgm_parameter_get_val(const pptx_ct_dgm_parameter *const obj);
int32_t pptx_ct_dgm_parameter_get_index(pptx_ct_dgm_parameter *obj);

#endif /* __PPTX_CT_DGM_PARAMETER_H__ */

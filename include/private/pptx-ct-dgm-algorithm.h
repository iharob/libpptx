#ifndef __PPTX_CT_DGM_ALGORITHM_H__
#define __PPTX_CT_DGM_ALGORITHM_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_parameter_s pptx_ct_dgm_parameter;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_algorithm_type_token_enum pptx_st_algorithm_type_token_enum;

typedef struct pptx_ct_dgm_algorithm_s pptx_ct_dgm_algorithm;
pptx_ct_dgm_algorithm *pptx_ct_dgm_algorithm_new(xmlNode *node);
void pptx_ct_dgm_algorithm_free(pptx_ct_dgm_algorithm *obj);
pptx_ct_dgm_parameter **pptx_ct_dgm_algorithm_get_param(const pptx_ct_dgm_algorithm *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_algorithm_get_ext_lst(const pptx_ct_dgm_algorithm *const obj);
pptx_st_algorithm_type_token_enum pptx_ct_dgm_algorithm_get_type(const pptx_ct_dgm_algorithm *const obj);
pptx_uint pptx_ct_dgm_algorithm_get_rev(const pptx_ct_dgm_algorithm *const obj);
int32_t pptx_ct_dgm_algorithm_get_index(pptx_ct_dgm_algorithm *obj);

#endif /* __PPTX_CT_DGM_ALGORITHM_H__ */

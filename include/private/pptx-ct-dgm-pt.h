#ifndef __PPTX_CT_DGM_PT_H__
#define __PPTX_CT_DGM_PT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_elem_prop_set_s pptx_ct_dgm_elem_prop_set;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_pt_type_token_enum pptx_st_pt_type_token_enum;

typedef struct pptx_ct_dgm_pt_s pptx_ct_dgm_pt;
pptx_ct_dgm_pt *pptx_ct_dgm_pt_new(xmlNode *node);
void pptx_ct_dgm_pt_free(pptx_ct_dgm_pt *obj);
pptx_ct_dgm_elem_prop_set *pptx_ct_dgm_pt_get_pr_set(const pptx_ct_dgm_pt *const obj);
pptx_ct_a_shape_properties *pptx_ct_dgm_pt_get_sp_pr(const pptx_ct_dgm_pt *const obj);
pptx_ct_a_text_body *pptx_ct_dgm_pt_get_t(const pptx_ct_dgm_pt *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_pt_get_ext_lst(const pptx_ct_dgm_pt *const obj);
pptx_string pptx_ct_dgm_pt_get_model_id(const pptx_ct_dgm_pt *const obj);
pptx_st_pt_type_token_enum pptx_ct_dgm_pt_get_type(const pptx_ct_dgm_pt *const obj);
pptx_string pptx_ct_dgm_pt_get_cxn_id(const pptx_ct_dgm_pt *const obj);
int32_t pptx_ct_dgm_pt_get_index(pptx_ct_dgm_pt *obj);

#endif /* __PPTX_CT_DGM_PT_H__ */

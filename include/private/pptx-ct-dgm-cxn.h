#ifndef __PPTX_CT_DGM_CXN_H__
#define __PPTX_CT_DGM_CXN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_cxn_type_token_enum pptx_st_cxn_type_token_enum;

typedef struct pptx_ct_dgm_cxn_s pptx_ct_dgm_cxn;
pptx_ct_dgm_cxn *pptx_ct_dgm_cxn_new(xmlNode *node);
void pptx_ct_dgm_cxn_free(pptx_ct_dgm_cxn *obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_cxn_get_ext_lst(const pptx_ct_dgm_cxn *const obj);
pptx_string pptx_ct_dgm_cxn_get_model_id(const pptx_ct_dgm_cxn *const obj);
pptx_st_cxn_type_token_enum pptx_ct_dgm_cxn_get_type(const pptx_ct_dgm_cxn *const obj);
pptx_string pptx_ct_dgm_cxn_get_src_id(const pptx_ct_dgm_cxn *const obj);
pptx_string pptx_ct_dgm_cxn_get_dest_id(const pptx_ct_dgm_cxn *const obj);
pptx_uint pptx_ct_dgm_cxn_get_src_ord(const pptx_ct_dgm_cxn *const obj);
pptx_uint pptx_ct_dgm_cxn_get_dest_ord(const pptx_ct_dgm_cxn *const obj);
pptx_string pptx_ct_dgm_cxn_get_par_trans_id(const pptx_ct_dgm_cxn *const obj);
pptx_string pptx_ct_dgm_cxn_get_sib_trans_id(const pptx_ct_dgm_cxn *const obj);
pptx_string pptx_ct_dgm_cxn_get_pres_id(const pptx_ct_dgm_cxn *const obj);
int32_t pptx_ct_dgm_cxn_get_index(pptx_ct_dgm_cxn *obj);

#endif /* __PPTX_CT_DGM_CXN_H__ */

#ifndef __PPTX_CT_P_MODIFY_VERIFIER_H__
#define __PPTX_CT_P_MODIFY_VERIFIER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_crypt_prov_text_enum pptx_st_crypt_prov_text_enum;
typedef enum pptx_st_alg_class_text_enum pptx_st_alg_class_text_enum;
typedef enum pptx_st_alg_type_text_enum pptx_st_alg_type_text_enum;

typedef struct pptx_ct_p_modify_verifier_s pptx_ct_p_modify_verifier;
pptx_ct_p_modify_verifier *pptx_ct_p_modify_verifier_new(xmlNode *node);
void pptx_ct_p_modify_verifier_free(pptx_ct_p_modify_verifier *obj);
pptx_string pptx_ct_p_modify_verifier_get_algorithm_name(const pptx_ct_p_modify_verifier *const obj);
pptx_string pptx_ct_p_modify_verifier_get_hash_value(const pptx_ct_p_modify_verifier *const obj);
pptx_string pptx_ct_p_modify_verifier_get_salt_value(const pptx_ct_p_modify_verifier *const obj);
pptx_uint pptx_ct_p_modify_verifier_get_spin_value(const pptx_ct_p_modify_verifier *const obj);
pptx_st_crypt_prov_text_enum pptx_ct_p_modify_verifier_get_crypt_provider_type(const pptx_ct_p_modify_verifier *const obj);
pptx_st_alg_class_text_enum pptx_ct_p_modify_verifier_get_crypt_algorithm_class(const pptx_ct_p_modify_verifier *const obj);
pptx_st_alg_type_text_enum pptx_ct_p_modify_verifier_get_crypt_algorithm_type(const pptx_ct_p_modify_verifier *const obj);
pptx_uint pptx_ct_p_modify_verifier_get_crypt_algorithm_sid(const pptx_ct_p_modify_verifier *const obj);
pptx_uint pptx_ct_p_modify_verifier_get_spin_count(const pptx_ct_p_modify_verifier *const obj);
pptx_string pptx_ct_p_modify_verifier_get_salt_data(const pptx_ct_p_modify_verifier *const obj);
pptx_string pptx_ct_p_modify_verifier_get_hash_data(const pptx_ct_p_modify_verifier *const obj);
pptx_string pptx_ct_p_modify_verifier_get_crypt_provider(const pptx_ct_p_modify_verifier *const obj);
pptx_uint pptx_ct_p_modify_verifier_get_alg_id_ext(const pptx_ct_p_modify_verifier *const obj);
pptx_string pptx_ct_p_modify_verifier_get_alg_id_ext_source(const pptx_ct_p_modify_verifier *const obj);
pptx_uint pptx_ct_p_modify_verifier_get_crypt_provider_type_ext(const pptx_ct_p_modify_verifier *const obj);
pptx_string pptx_ct_p_modify_verifier_get_crypt_provider_type_ext_source(const pptx_ct_p_modify_verifier *const obj);
int32_t pptx_ct_p_modify_verifier_get_index(pptx_ct_p_modify_verifier *obj);

#endif /* __PPTX_CT_P_MODIFY_VERIFIER_H__ */

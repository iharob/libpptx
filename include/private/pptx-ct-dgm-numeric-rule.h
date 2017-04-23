#ifndef __PPTX_CT_DGM_NUMERIC_RULE_H__
#define __PPTX_CT_DGM_NUMERIC_RULE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_constraint_type_token_enum pptx_st_constraint_type_token_enum;
typedef enum pptx_st_constraint_relationship_token_enum pptx_st_constraint_relationship_token_enum;
typedef enum pptx_st_element_type_token_enum pptx_st_element_type_token_enum;

typedef struct pptx_ct_dgm_numeric_rule_s pptx_ct_dgm_numeric_rule;
pptx_ct_dgm_numeric_rule *pptx_ct_dgm_numeric_rule_new(xmlNode *node);
void pptx_ct_dgm_numeric_rule_free(pptx_ct_dgm_numeric_rule *obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_numeric_rule_get_ext_lst(const pptx_ct_dgm_numeric_rule *const obj);
pptx_st_constraint_type_token_enum pptx_ct_dgm_numeric_rule_get_type(const pptx_ct_dgm_numeric_rule *const obj);
pptx_st_constraint_relationship_token_enum pptx_ct_dgm_numeric_rule_get__for(const pptx_ct_dgm_numeric_rule *const obj);
pptx_string pptx_ct_dgm_numeric_rule_get_for_name(const pptx_ct_dgm_numeric_rule *const obj);
pptx_st_element_type_token_enum pptx_ct_dgm_numeric_rule_get_pt_type(const pptx_ct_dgm_numeric_rule *const obj);
pptx_double pptx_ct_dgm_numeric_rule_get_val(const pptx_ct_dgm_numeric_rule *const obj);
pptx_double pptx_ct_dgm_numeric_rule_get_fact(const pptx_ct_dgm_numeric_rule *const obj);
pptx_double pptx_ct_dgm_numeric_rule_get_max(const pptx_ct_dgm_numeric_rule *const obj);
int32_t pptx_ct_dgm_numeric_rule_get_index(pptx_ct_dgm_numeric_rule *obj);

#endif /* __PPTX_CT_DGM_NUMERIC_RULE_H__ */

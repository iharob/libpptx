#ifndef __PPTX_CT_DGM_WHEN_H__
#define __PPTX_CT_DGM_WHEN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_algorithm_s pptx_ct_dgm_algorithm;
typedef struct pptx_ct_dgm_shape_s pptx_ct_dgm_shape;
typedef struct pptx_ct_dgm_presentation_of_s pptx_ct_dgm_presentation_of;
typedef struct pptx_ct_dgm_constraints_s pptx_ct_dgm_constraints;
typedef struct pptx_ct_dgm_rules_s pptx_ct_dgm_rules;
typedef struct pptx_ct_dgm_for_each_s pptx_ct_dgm_for_each;
typedef struct pptx_ct_dgm_layout_node_s pptx_ct_dgm_layout_node;
typedef struct pptx_ct_dgm_choose_s pptx_ct_dgm_choose;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_axis_type_token_enum pptx_st_axis_type_token_enum;
typedef enum pptx_st_element_type_token_enum pptx_st_element_type_token_enum;
typedef enum pptx_st_function_type_token_enum pptx_st_function_type_token_enum;
typedef enum pptx_st_variable_type_token_enum pptx_st_variable_type_token_enum;
typedef enum pptx_st_function_operator_token_enum pptx_st_function_operator_token_enum;
typedef enum pptx_st_resize_handles_str_token_enum pptx_st_resize_handles_str_token_enum;

typedef struct pptx_ct_dgm_when_s pptx_ct_dgm_when;
pptx_ct_dgm_when *pptx_ct_dgm_when_new(xmlNode *node);
void pptx_ct_dgm_when_free(pptx_ct_dgm_when *obj);
pptx_ct_dgm_algorithm **pptx_ct_dgm_when_get_alg(const pptx_ct_dgm_when *const obj);
pptx_ct_dgm_shape **pptx_ct_dgm_when_get_shape(const pptx_ct_dgm_when *const obj);
pptx_ct_dgm_presentation_of **pptx_ct_dgm_when_get_pres_of(const pptx_ct_dgm_when *const obj);
pptx_ct_dgm_constraints **pptx_ct_dgm_when_get_constr_lst(const pptx_ct_dgm_when *const obj);
pptx_ct_dgm_rules **pptx_ct_dgm_when_get_rule_lst(const pptx_ct_dgm_when *const obj);
pptx_ct_dgm_for_each **pptx_ct_dgm_when_get_for_each(const pptx_ct_dgm_when *const obj);
pptx_ct_dgm_layout_node **pptx_ct_dgm_when_get_layout_node(const pptx_ct_dgm_when *const obj);
pptx_ct_dgm_choose **pptx_ct_dgm_when_get_choose(const pptx_ct_dgm_when *const obj);
pptx_ct_a_office_art_extension_list **pptx_ct_dgm_when_get_ext_lst(const pptx_ct_dgm_when *const obj);
pptx_string pptx_ct_dgm_when_get_name(const pptx_ct_dgm_when *const obj);
pptx_st_axis_type_token_enum pptx_ct_dgm_when_get_axis(const pptx_ct_dgm_when *const obj);
pptx_st_element_type_token_enum pptx_ct_dgm_when_get_pt_type(const pptx_ct_dgm_when *const obj);
pptx_bool pptx_ct_dgm_when_get_hide_last_trans(const pptx_ct_dgm_when *const obj);
pptx_int pptx_ct_dgm_when_get_st(const pptx_ct_dgm_when *const obj);
pptx_uint pptx_ct_dgm_when_get_cnt(const pptx_ct_dgm_when *const obj);
pptx_int pptx_ct_dgm_when_get_step(const pptx_ct_dgm_when *const obj);
pptx_st_function_type_token_enum pptx_ct_dgm_when_get_func(const pptx_ct_dgm_when *const obj);
pptx_st_variable_type_token_enum pptx_ct_dgm_when_get_arg(const pptx_ct_dgm_when *const obj);
pptx_st_function_operator_token_enum pptx_ct_dgm_when_get_op(const pptx_ct_dgm_when *const obj);
pptx_st_resize_handles_str_token_enum pptx_ct_dgm_when_get_val(const pptx_ct_dgm_when *const obj);
int32_t pptx_ct_dgm_when_get_index(pptx_ct_dgm_when *obj);

#endif /* __PPTX_CT_DGM_WHEN_H__ */

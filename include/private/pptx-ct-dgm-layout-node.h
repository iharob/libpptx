#ifndef __PPTX_CT_DGM_LAYOUT_NODE_H__
#define __PPTX_CT_DGM_LAYOUT_NODE_H__

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
typedef struct pptx_ct_dgm_layout_variable_property_set_s pptx_ct_dgm_layout_variable_property_set;
typedef struct pptx_ct_dgm_for_each_s pptx_ct_dgm_for_each;
typedef struct pptx_ct_dgm_layout_node_s pptx_ct_dgm_layout_node;
typedef struct pptx_ct_dgm_choose_s pptx_ct_dgm_choose;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_child_order_type_token_enum pptx_st_child_order_type_token_enum;

typedef struct pptx_ct_dgm_layout_node_s pptx_ct_dgm_layout_node;
pptx_ct_dgm_layout_node *pptx_ct_dgm_layout_node_new(xmlNode *node);
void pptx_ct_dgm_layout_node_free(pptx_ct_dgm_layout_node *obj);
pptx_ct_dgm_algorithm **pptx_ct_dgm_layout_node_get_alg(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_dgm_shape **pptx_ct_dgm_layout_node_get_shape(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_dgm_presentation_of **pptx_ct_dgm_layout_node_get_pres_of(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_dgm_constraints **pptx_ct_dgm_layout_node_get_constr_lst(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_dgm_rules **pptx_ct_dgm_layout_node_get_rule_lst(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_dgm_layout_variable_property_set **pptx_ct_dgm_layout_node_get_var_lst(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_dgm_for_each **pptx_ct_dgm_layout_node_get_for_each(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_dgm_layout_node **pptx_ct_dgm_layout_node_get_layout_node(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_dgm_choose **pptx_ct_dgm_layout_node_get_choose(const pptx_ct_dgm_layout_node *const obj);
pptx_ct_a_office_art_extension_list **pptx_ct_dgm_layout_node_get_ext_lst(const pptx_ct_dgm_layout_node *const obj);
pptx_string pptx_ct_dgm_layout_node_get_name(const pptx_ct_dgm_layout_node *const obj);
pptx_string pptx_ct_dgm_layout_node_get_style_lbl(const pptx_ct_dgm_layout_node *const obj);
pptx_st_child_order_type_token_enum pptx_ct_dgm_layout_node_get_ch_order(const pptx_ct_dgm_layout_node *const obj);
pptx_string pptx_ct_dgm_layout_node_get_move_with(const pptx_ct_dgm_layout_node *const obj);
int32_t pptx_ct_dgm_layout_node_get_index(pptx_ct_dgm_layout_node *obj);

#endif /* __PPTX_CT_DGM_LAYOUT_NODE_H__ */

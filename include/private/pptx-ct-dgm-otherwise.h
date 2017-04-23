#ifndef __PPTX_CT_DGM_OTHERWISE_H__
#define __PPTX_CT_DGM_OTHERWISE_H__

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

typedef struct pptx_ct_dgm_otherwise_s pptx_ct_dgm_otherwise;
pptx_ct_dgm_otherwise *pptx_ct_dgm_otherwise_new(xmlNode *node);
void pptx_ct_dgm_otherwise_free(pptx_ct_dgm_otherwise *obj);
pptx_ct_dgm_algorithm **pptx_ct_dgm_otherwise_get_alg(const pptx_ct_dgm_otherwise *const obj);
pptx_ct_dgm_shape **pptx_ct_dgm_otherwise_get_shape(const pptx_ct_dgm_otherwise *const obj);
pptx_ct_dgm_presentation_of **pptx_ct_dgm_otherwise_get_pres_of(const pptx_ct_dgm_otherwise *const obj);
pptx_ct_dgm_constraints **pptx_ct_dgm_otherwise_get_constr_lst(const pptx_ct_dgm_otherwise *const obj);
pptx_ct_dgm_rules **pptx_ct_dgm_otherwise_get_rule_lst(const pptx_ct_dgm_otherwise *const obj);
pptx_ct_dgm_for_each **pptx_ct_dgm_otherwise_get_for_each(const pptx_ct_dgm_otherwise *const obj);
pptx_ct_dgm_layout_node **pptx_ct_dgm_otherwise_get_layout_node(const pptx_ct_dgm_otherwise *const obj);
pptx_ct_dgm_choose **pptx_ct_dgm_otherwise_get_choose(const pptx_ct_dgm_otherwise *const obj);
pptx_ct_a_office_art_extension_list **pptx_ct_dgm_otherwise_get_ext_lst(const pptx_ct_dgm_otherwise *const obj);
pptx_string pptx_ct_dgm_otherwise_get_name(const pptx_ct_dgm_otherwise *const obj);
int32_t pptx_ct_dgm_otherwise_get_index(pptx_ct_dgm_otherwise *obj);

#endif /* __PPTX_CT_DGM_OTHERWISE_H__ */

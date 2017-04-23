#ifndef __PPTX_CT_DGM_RULES_H__
#define __PPTX_CT_DGM_RULES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_numeric_rule_s pptx_ct_dgm_numeric_rule;

typedef struct pptx_ct_dgm_rules_s pptx_ct_dgm_rules;
pptx_ct_dgm_rules *pptx_ct_dgm_rules_new(xmlNode *node);
void pptx_ct_dgm_rules_free(pptx_ct_dgm_rules *obj);
pptx_ct_dgm_numeric_rule **pptx_ct_dgm_rules_get_rule(const pptx_ct_dgm_rules *const obj);
int32_t pptx_ct_dgm_rules_get_index(pptx_ct_dgm_rules *obj);

#endif /* __PPTX_CT_DGM_RULES_H__ */

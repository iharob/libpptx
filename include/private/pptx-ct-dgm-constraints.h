#ifndef __PPTX_CT_DGM_CONSTRAINTS_H__
#define __PPTX_CT_DGM_CONSTRAINTS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_constraint_s pptx_ct_dgm_constraint;

typedef struct pptx_ct_dgm_constraints_s pptx_ct_dgm_constraints;
pptx_ct_dgm_constraints *pptx_ct_dgm_constraints_new(xmlNode *node);
void pptx_ct_dgm_constraints_free(pptx_ct_dgm_constraints *obj);
pptx_ct_dgm_constraint **pptx_ct_dgm_constraints_get_constr(const pptx_ct_dgm_constraints *const obj);
int32_t pptx_ct_dgm_constraints_get_index(pptx_ct_dgm_constraints *obj);

#endif /* __PPTX_CT_DGM_CONSTRAINTS_H__ */

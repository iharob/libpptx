#ifndef __PPTX_CT_DGM_HIER_BRANCH_STYLE_H__
#define __PPTX_CT_DGM_HIER_BRANCH_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_hier_branch_style_token_enum pptx_st_hier_branch_style_token_enum;

typedef struct pptx_ct_dgm_hier_branch_style_s pptx_ct_dgm_hier_branch_style;
pptx_ct_dgm_hier_branch_style *pptx_ct_dgm_hier_branch_style_new(xmlNode *node);
void pptx_ct_dgm_hier_branch_style_free(pptx_ct_dgm_hier_branch_style *obj);
pptx_st_hier_branch_style_token_enum pptx_ct_dgm_hier_branch_style_get_val(const pptx_ct_dgm_hier_branch_style *const obj);
int32_t pptx_ct_dgm_hier_branch_style_get_index(pptx_ct_dgm_hier_branch_style *obj);

#endif /* __PPTX_CT_DGM_HIER_BRANCH_STYLE_H__ */

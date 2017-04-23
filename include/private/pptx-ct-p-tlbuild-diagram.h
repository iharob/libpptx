#ifndef __PPTX_CT_P_TLBUILD_DIAGRAM_H__
#define __PPTX_CT_P_TLBUILD_DIAGRAM_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tldiagram_build_type_token_enum pptx_st_tldiagram_build_type_token_enum;

typedef struct pptx_ct_p_tlbuild_diagram_s pptx_ct_p_tlbuild_diagram;
pptx_ct_p_tlbuild_diagram *pptx_ct_p_tlbuild_diagram_new(xmlNode *node);
void pptx_ct_p_tlbuild_diagram_free(pptx_ct_p_tlbuild_diagram *obj);
pptx_uint pptx_ct_p_tlbuild_diagram_get_spid(const pptx_ct_p_tlbuild_diagram *const obj);
pptx_uint pptx_ct_p_tlbuild_diagram_get_grp_id(const pptx_ct_p_tlbuild_diagram *const obj);
pptx_bool pptx_ct_p_tlbuild_diagram_get_ui_expand(const pptx_ct_p_tlbuild_diagram *const obj);
pptx_st_tldiagram_build_type_token_enum pptx_ct_p_tlbuild_diagram_get_bld(const pptx_ct_p_tlbuild_diagram *const obj);
int32_t pptx_ct_p_tlbuild_diagram_get_index(pptx_ct_p_tlbuild_diagram *obj);

#endif /* __PPTX_CT_P_TLBUILD_DIAGRAM_H__ */

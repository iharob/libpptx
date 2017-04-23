#ifndef __PPTX_CT_P_TLBUILD_PARAGRAPH_H__
#define __PPTX_CT_P_TLBUILD_PARAGRAPH_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tltemplate_list_s pptx_ct_p_tltemplate_list;
typedef enum pptx_st_tlpara_build_type_token_enum pptx_st_tlpara_build_type_token_enum;
typedef enum pptx_st_tltime_indefinite_token_enum pptx_st_tltime_indefinite_token_enum;

typedef struct pptx_ct_p_tlbuild_paragraph_s pptx_ct_p_tlbuild_paragraph;
pptx_ct_p_tlbuild_paragraph *pptx_ct_p_tlbuild_paragraph_new(xmlNode *node);
void pptx_ct_p_tlbuild_paragraph_free(pptx_ct_p_tlbuild_paragraph *obj);
pptx_ct_p_tltemplate_list *pptx_ct_p_tlbuild_paragraph_get_tmpl_lst(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_uint pptx_ct_p_tlbuild_paragraph_get_spid(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_uint pptx_ct_p_tlbuild_paragraph_get_grp_id(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_bool pptx_ct_p_tlbuild_paragraph_get_ui_expand(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_st_tlpara_build_type_token_enum pptx_ct_p_tlbuild_paragraph_get_build(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_uint pptx_ct_p_tlbuild_paragraph_get_bld_lvl(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_bool pptx_ct_p_tlbuild_paragraph_get_anim_bg(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_bool pptx_ct_p_tlbuild_paragraph_get_auto_update_anim_bg(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_bool pptx_ct_p_tlbuild_paragraph_get_rev(const pptx_ct_p_tlbuild_paragraph *const obj);
pptx_st_tltime_indefinite_token_enum pptx_ct_p_tlbuild_paragraph_get_adv_auto(const pptx_ct_p_tlbuild_paragraph *const obj);
int32_t pptx_ct_p_tlbuild_paragraph_get_index(pptx_ct_p_tlbuild_paragraph *obj);

#endif /* __PPTX_CT_P_TLBUILD_PARAGRAPH_H__ */

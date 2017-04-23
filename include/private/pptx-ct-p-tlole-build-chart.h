#ifndef __PPTX_CT_P_TLOLE_BUILD_CHART_H__
#define __PPTX_CT_P_TLOLE_BUILD_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlole_chart_build_type_token_enum pptx_st_tlole_chart_build_type_token_enum;

typedef struct pptx_ct_p_tlole_build_chart_s pptx_ct_p_tlole_build_chart;
pptx_ct_p_tlole_build_chart *pptx_ct_p_tlole_build_chart_new(xmlNode *node);
void pptx_ct_p_tlole_build_chart_free(pptx_ct_p_tlole_build_chart *obj);
pptx_uint pptx_ct_p_tlole_build_chart_get_spid(const pptx_ct_p_tlole_build_chart *const obj);
pptx_uint pptx_ct_p_tlole_build_chart_get_grp_id(const pptx_ct_p_tlole_build_chart *const obj);
pptx_bool pptx_ct_p_tlole_build_chart_get_ui_expand(const pptx_ct_p_tlole_build_chart *const obj);
pptx_st_tlole_chart_build_type_token_enum pptx_ct_p_tlole_build_chart_get_bld(const pptx_ct_p_tlole_build_chart *const obj);
pptx_bool pptx_ct_p_tlole_build_chart_get_anim_bg(const pptx_ct_p_tlole_build_chart *const obj);
int32_t pptx_ct_p_tlole_build_chart_get_index(pptx_ct_p_tlole_build_chart *obj);

#endif /* __PPTX_CT_P_TLOLE_BUILD_CHART_H__ */

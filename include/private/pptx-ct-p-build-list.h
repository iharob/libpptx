#ifndef __PPTX_CT_P_BUILD_LIST_H__
#define __PPTX_CT_P_BUILD_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tlbuild_paragraph_s pptx_ct_p_tlbuild_paragraph;
typedef struct pptx_ct_p_tlbuild_diagram_s pptx_ct_p_tlbuild_diagram;
typedef struct pptx_ct_p_tlole_build_chart_s pptx_ct_p_tlole_build_chart;
typedef struct pptx_ct_p_tlgraphical_object_build_s pptx_ct_p_tlgraphical_object_build;

typedef struct pptx_ct_p_build_list_s pptx_ct_p_build_list;
pptx_ct_p_build_list *pptx_ct_p_build_list_new(xmlNode *node);
void pptx_ct_p_build_list_free(pptx_ct_p_build_list *obj);
pptx_ct_p_tlbuild_paragraph **pptx_ct_p_build_list_get_bld_p(const pptx_ct_p_build_list *const obj);
pptx_ct_p_tlbuild_diagram **pptx_ct_p_build_list_get_bld_dgm(const pptx_ct_p_build_list *const obj);
pptx_ct_p_tlole_build_chart **pptx_ct_p_build_list_get_bld_ole_chart(const pptx_ct_p_build_list *const obj);
pptx_ct_p_tlgraphical_object_build **pptx_ct_p_build_list_get_bld_graphic(const pptx_ct_p_build_list *const obj);
int32_t pptx_ct_p_build_list_get_index(pptx_ct_p_build_list *obj);

#endif /* __PPTX_CT_P_BUILD_LIST_H__ */

#ifndef __PPTX_CT_P_SLIDE_TIMING_H__
#define __PPTX_CT_P_SLIDE_TIMING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_time_node_list_s pptx_ct_p_time_node_list;
typedef struct pptx_ct_p_build_list_s pptx_ct_p_build_list;
typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;

typedef struct pptx_ct_p_slide_timing_s pptx_ct_p_slide_timing;
pptx_ct_p_slide_timing *pptx_ct_p_slide_timing_new(xmlNode *node);
void pptx_ct_p_slide_timing_free(pptx_ct_p_slide_timing *obj);
pptx_ct_p_time_node_list *pptx_ct_p_slide_timing_get_tn_lst(const pptx_ct_p_slide_timing *const obj);
pptx_ct_p_build_list *pptx_ct_p_slide_timing_get_bld_lst(const pptx_ct_p_slide_timing *const obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_slide_timing_get_ext_lst(const pptx_ct_p_slide_timing *const obj);
int32_t pptx_ct_p_slide_timing_get_index(pptx_ct_p_slide_timing *obj);

#endif /* __PPTX_CT_P_SLIDE_TIMING_H__ */

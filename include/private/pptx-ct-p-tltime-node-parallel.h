#ifndef __PPTX_CT_P_TLTIME_NODE_PARALLEL_H__
#define __PPTX_CT_P_TLTIME_NODE_PARALLEL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tlcommon_time_node_data_s pptx_ct_p_tlcommon_time_node_data;

typedef struct pptx_ct_p_tltime_node_parallel_s pptx_ct_p_tltime_node_parallel;
pptx_ct_p_tltime_node_parallel *pptx_ct_p_tltime_node_parallel_new(xmlNode *node);
void pptx_ct_p_tltime_node_parallel_free(pptx_ct_p_tltime_node_parallel *obj);
pptx_ct_p_tlcommon_time_node_data *pptx_ct_p_tltime_node_parallel_get_c_tn(const pptx_ct_p_tltime_node_parallel *const obj);
int32_t pptx_ct_p_tltime_node_parallel_get_index(pptx_ct_p_tltime_node_parallel *obj);

#endif /* __PPTX_CT_P_TLTIME_NODE_PARALLEL_H__ */

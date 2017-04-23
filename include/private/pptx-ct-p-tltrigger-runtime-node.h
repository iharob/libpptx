#ifndef __PPTX_CT_P_TLTRIGGER_RUNTIME_NODE_H__
#define __PPTX_CT_P_TLTRIGGER_RUNTIME_NODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltrigger_runtime_node_token_enum pptx_st_tltrigger_runtime_node_token_enum;

typedef struct pptx_ct_p_tltrigger_runtime_node_s pptx_ct_p_tltrigger_runtime_node;
pptx_ct_p_tltrigger_runtime_node *pptx_ct_p_tltrigger_runtime_node_new(xmlNode *node);
void pptx_ct_p_tltrigger_runtime_node_free(pptx_ct_p_tltrigger_runtime_node *obj);
pptx_st_tltrigger_runtime_node_token_enum pptx_ct_p_tltrigger_runtime_node_get_val(const pptx_ct_p_tltrigger_runtime_node *const obj);
int32_t pptx_ct_p_tltrigger_runtime_node_get_index(pptx_ct_p_tltrigger_runtime_node *obj);

#endif /* __PPTX_CT_P_TLTRIGGER_RUNTIME_NODE_H__ */

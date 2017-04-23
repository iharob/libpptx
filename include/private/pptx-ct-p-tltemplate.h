#ifndef __PPTX_CT_P_TLTEMPLATE_H__
#define __PPTX_CT_P_TLTEMPLATE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_time_node_list_s pptx_ct_p_time_node_list;

typedef struct pptx_ct_p_tltemplate_s pptx_ct_p_tltemplate;
pptx_ct_p_tltemplate *pptx_ct_p_tltemplate_new(xmlNode *node);
void pptx_ct_p_tltemplate_free(pptx_ct_p_tltemplate *obj);
pptx_ct_p_time_node_list *pptx_ct_p_tltemplate_get_tn_lst(const pptx_ct_p_tltemplate *const obj);
pptx_uint pptx_ct_p_tltemplate_get_lvl(const pptx_ct_p_tltemplate *const obj);
int32_t pptx_ct_p_tltemplate_get_index(pptx_ct_p_tltemplate *obj);

#endif /* __PPTX_CT_P_TLTEMPLATE_H__ */

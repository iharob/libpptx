#ifndef __PPTX_CT_P_TLBEHAVIOR_ATTRIBUTE_NAME_LIST_H__
#define __PPTX_CT_P_TLBEHAVIOR_ATTRIBUTE_NAME_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_tlbehavior_attribute_name_list_s pptx_ct_p_tlbehavior_attribute_name_list;
pptx_ct_p_tlbehavior_attribute_name_list *pptx_ct_p_tlbehavior_attribute_name_list_new(xmlNode *node);
void pptx_ct_p_tlbehavior_attribute_name_list_free(pptx_ct_p_tlbehavior_attribute_name_list *obj);
int32_t pptx_ct_p_tlbehavior_attribute_name_list_get_index(pptx_ct_p_tlbehavior_attribute_name_list *obj);

#endif /* __PPTX_CT_P_TLBEHAVIOR_ATTRIBUTE_NAME_LIST_H__ */

#ifndef __PPTX_CT_P_CONTROL_LIST_H__
#define __PPTX_CT_P_CONTROL_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_control_s pptx_ct_p_control;

typedef struct pptx_ct_p_control_list_s pptx_ct_p_control_list;
pptx_ct_p_control_list *pptx_ct_p_control_list_new(xmlNode *node);
void pptx_ct_p_control_list_free(pptx_ct_p_control_list *obj);
pptx_ct_p_control **pptx_ct_p_control_list_get_control(const pptx_ct_p_control_list *const obj);
int32_t pptx_ct_p_control_list_get_index(pptx_ct_p_control_list *obj);

#endif /* __PPTX_CT_P_CONTROL_LIST_H__ */

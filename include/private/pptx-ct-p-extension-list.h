#ifndef __PPTX_CT_P_EXTENSION_LIST_H__
#define __PPTX_CT_P_EXTENSION_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_s pptx_ct_p_extension;

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;
pptx_ct_p_extension_list *pptx_ct_p_extension_list_new(xmlNode *node);
void pptx_ct_p_extension_list_free(pptx_ct_p_extension_list *obj);
pptx_ct_p_extension **pptx_ct_p_extension_list_get_extension_list_ext(const pptx_ct_p_extension_list *const obj);
int32_t pptx_ct_p_extension_list_get_index(pptx_ct_p_extension_list *obj);

#endif /* __PPTX_CT_P_EXTENSION_LIST_H__ */

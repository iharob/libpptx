#ifndef __PPTX_CT_P_OLE_OBJECT_LINK_H__
#define __PPTX_CT_P_OLE_OBJECT_LINK_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;

typedef struct pptx_ct_p_ole_object_link_s pptx_ct_p_ole_object_link;
pptx_ct_p_ole_object_link *pptx_ct_p_ole_object_link_new(xmlNode *node);
void pptx_ct_p_ole_object_link_free(pptx_ct_p_ole_object_link *obj);
pptx_ct_p_extension_list *pptx_ct_p_ole_object_link_get_ext_lst(const pptx_ct_p_ole_object_link *const obj);
pptx_bool pptx_ct_p_ole_object_link_get_update_automatic(const pptx_ct_p_ole_object_link *const obj);
int32_t pptx_ct_p_ole_object_link_get_index(pptx_ct_p_ole_object_link *obj);

#endif /* __PPTX_CT_P_OLE_OBJECT_LINK_H__ */

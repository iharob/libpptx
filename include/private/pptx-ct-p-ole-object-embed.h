#ifndef __PPTX_CT_P_OLE_OBJECT_EMBED_H__
#define __PPTX_CT_P_OLE_OBJECT_EMBED_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;
typedef enum pptx_st_ole_object_follow_color_scheme_token_enum pptx_st_ole_object_follow_color_scheme_token_enum;

typedef struct pptx_ct_p_ole_object_embed_s pptx_ct_p_ole_object_embed;
pptx_ct_p_ole_object_embed *pptx_ct_p_ole_object_embed_new(xmlNode *node);
void pptx_ct_p_ole_object_embed_free(pptx_ct_p_ole_object_embed *obj);
pptx_ct_p_extension_list *pptx_ct_p_ole_object_embed_get_ext_lst(const pptx_ct_p_ole_object_embed *const obj);
pptx_st_ole_object_follow_color_scheme_token_enum pptx_ct_p_ole_object_embed_get_follow_color_scheme(const pptx_ct_p_ole_object_embed *const obj);
int32_t pptx_ct_p_ole_object_embed_get_index(pptx_ct_p_ole_object_embed *obj);

#endif /* __PPTX_CT_P_OLE_OBJECT_EMBED_H__ */

#ifndef __PPTX_CT_P_OLE_OBJECT_H__
#define __PPTX_CT_P_OLE_OBJECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_ole_object_embed_s pptx_ct_p_ole_object_embed;
typedef struct pptx_ct_p_ole_object_link_s pptx_ct_p_ole_object_link;
typedef struct pptx_ct_p_picture_s pptx_ct_p_picture;

typedef struct pptx_ct_p_ole_object_s pptx_ct_p_ole_object;
pptx_ct_p_ole_object *pptx_ct_p_ole_object_new(xmlNode *node);
void pptx_ct_p_ole_object_free(pptx_ct_p_ole_object *obj);
pptx_ct_p_ole_object_embed *pptx_ct_p_ole_object_get_embed(const pptx_ct_p_ole_object *const obj);
pptx_ct_p_ole_object_link *pptx_ct_p_ole_object_get_link(const pptx_ct_p_ole_object *const obj);
pptx_ct_p_picture *pptx_ct_p_ole_object_get_pic(const pptx_ct_p_ole_object *const obj);
pptx_string pptx_ct_p_ole_object_get_spid(const pptx_ct_p_ole_object *const obj);
pptx_string pptx_ct_p_ole_object_get_name(const pptx_ct_p_ole_object *const obj);
pptx_bool pptx_ct_p_ole_object_get_show_as_icon(const pptx_ct_p_ole_object *const obj);
pptx_string pptx_ct_p_ole_object_get_r_id(const pptx_ct_p_ole_object *const obj);
pptx_int pptx_ct_p_ole_object_get_img_w(const pptx_ct_p_ole_object *const obj);
pptx_int pptx_ct_p_ole_object_get_img_h(const pptx_ct_p_ole_object *const obj);
pptx_string pptx_ct_p_ole_object_get_prog_id(const pptx_ct_p_ole_object *const obj);
int32_t pptx_ct_p_ole_object_get_index(pptx_ct_p_ole_object *obj);

#endif /* __PPTX_CT_P_OLE_OBJECT_H__ */

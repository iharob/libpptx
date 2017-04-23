#ifndef __PPTX_CT_P_CONTROL_H__
#define __PPTX_CT_P_CONTROL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;
typedef struct pptx_ct_p_picture_s pptx_ct_p_picture;

typedef struct pptx_ct_p_control_s pptx_ct_p_control;
pptx_ct_p_control *pptx_ct_p_control_new(xmlNode *node);
void pptx_ct_p_control_free(pptx_ct_p_control *obj);
pptx_ct_p_extension_list *pptx_ct_p_control_get_ext_lst(const pptx_ct_p_control *const obj);
pptx_ct_p_picture *pptx_ct_p_control_get_pic(const pptx_ct_p_control *const obj);
pptx_string pptx_ct_p_control_get_spid(const pptx_ct_p_control *const obj);
pptx_string pptx_ct_p_control_get_name(const pptx_ct_p_control *const obj);
pptx_bool pptx_ct_p_control_get_show_as_icon(const pptx_ct_p_control *const obj);
pptx_string pptx_ct_p_control_get_r_id(const pptx_ct_p_control *const obj);
pptx_int pptx_ct_p_control_get_img_w(const pptx_ct_p_control *const obj);
pptx_int pptx_ct_p_control_get_img_h(const pptx_ct_p_control *const obj);
int32_t pptx_ct_p_control_get_index(pptx_ct_p_control *obj);

#endif /* __PPTX_CT_P_CONTROL_H__ */

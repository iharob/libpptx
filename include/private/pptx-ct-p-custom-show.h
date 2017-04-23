#ifndef __PPTX_CT_P_CUSTOM_SHOW_H__
#define __PPTX_CT_P_CUSTOM_SHOW_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_slide_relationship_list_s pptx_ct_p_slide_relationship_list;
typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;

typedef struct pptx_ct_p_custom_show_s pptx_ct_p_custom_show;
pptx_ct_p_custom_show *pptx_ct_p_custom_show_new(xmlNode *node);
void pptx_ct_p_custom_show_free(pptx_ct_p_custom_show *obj);
pptx_ct_p_slide_relationship_list *pptx_ct_p_custom_show_get_sld_lst(const pptx_ct_p_custom_show *const obj);
pptx_ct_p_extension_list *pptx_ct_p_custom_show_get_ext_lst(const pptx_ct_p_custom_show *const obj);
pptx_string pptx_ct_p_custom_show_get_name(const pptx_ct_p_custom_show *const obj);
pptx_uint pptx_ct_p_custom_show_get_id(const pptx_ct_p_custom_show *const obj);
int32_t pptx_ct_p_custom_show_get_index(pptx_ct_p_custom_show *obj);

#endif /* __PPTX_CT_P_CUSTOM_SHOW_H__ */

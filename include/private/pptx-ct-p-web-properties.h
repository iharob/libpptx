#ifndef __PPTX_CT_P_WEB_PROPERTIES_H__
#define __PPTX_CT_P_WEB_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;
typedef enum pptx_st_web_screen_size_token_enum pptx_st_web_screen_size_token_enum;
typedef enum pptx_st_web_color_type_token_enum pptx_st_web_color_type_token_enum;

typedef struct pptx_ct_p_web_properties_s pptx_ct_p_web_properties;
pptx_ct_p_web_properties *pptx_ct_p_web_properties_new(xmlNode *node);
void pptx_ct_p_web_properties_free(pptx_ct_p_web_properties *obj);
pptx_ct_p_extension_list *pptx_ct_p_web_properties_get_ext_lst(const pptx_ct_p_web_properties *const obj);
pptx_bool pptx_ct_p_web_properties_get_show_animation(const pptx_ct_p_web_properties *const obj);
pptx_bool pptx_ct_p_web_properties_get_resize_graphics(const pptx_ct_p_web_properties *const obj);
pptx_bool pptx_ct_p_web_properties_get_allow_png(const pptx_ct_p_web_properties *const obj);
pptx_bool pptx_ct_p_web_properties_get_rely_on_vml(const pptx_ct_p_web_properties *const obj);
pptx_bool pptx_ct_p_web_properties_get_organize_in_folders(const pptx_ct_p_web_properties *const obj);
pptx_bool pptx_ct_p_web_properties_get_use_long_filenames(const pptx_ct_p_web_properties *const obj);
pptx_st_web_screen_size_token_enum pptx_ct_p_web_properties_get_img_sz(const pptx_ct_p_web_properties *const obj);
pptx_string pptx_ct_p_web_properties_get_encoding(const pptx_ct_p_web_properties *const obj);
pptx_st_web_color_type_token_enum pptx_ct_p_web_properties_get_clr(const pptx_ct_p_web_properties *const obj);
int32_t pptx_ct_p_web_properties_get_index(pptx_ct_p_web_properties *obj);

#endif /* __PPTX_CT_P_WEB_PROPERTIES_H__ */

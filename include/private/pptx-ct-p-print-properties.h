#ifndef __PPTX_CT_P_PRINT_PROPERTIES_H__
#define __PPTX_CT_P_PRINT_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;
typedef enum pptx_st_print_what_token_enum pptx_st_print_what_token_enum;
typedef enum pptx_st_print_color_mode_token_enum pptx_st_print_color_mode_token_enum;

typedef struct pptx_ct_p_print_properties_s pptx_ct_p_print_properties;
pptx_ct_p_print_properties *pptx_ct_p_print_properties_new(xmlNode *node);
void pptx_ct_p_print_properties_free(pptx_ct_p_print_properties *obj);
pptx_ct_p_extension_list *pptx_ct_p_print_properties_get_ext_lst(const pptx_ct_p_print_properties *const obj);
pptx_st_print_what_token_enum pptx_ct_p_print_properties_get_prn_what(const pptx_ct_p_print_properties *const obj);
pptx_st_print_color_mode_token_enum pptx_ct_p_print_properties_get_clr_mode(const pptx_ct_p_print_properties *const obj);
pptx_bool pptx_ct_p_print_properties_get_hidden_slides(const pptx_ct_p_print_properties *const obj);
pptx_bool pptx_ct_p_print_properties_get_scale_to_fit_paper(const pptx_ct_p_print_properties *const obj);
pptx_bool pptx_ct_p_print_properties_get_frame_slides(const pptx_ct_p_print_properties *const obj);
int32_t pptx_ct_p_print_properties_get_index(pptx_ct_p_print_properties *obj);

#endif /* __PPTX_CT_P_PRINT_PROPERTIES_H__ */

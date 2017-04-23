#ifndef __PPTX_CT_P_SLIDE_MASTER_TEXT_STYLES_H__
#define __PPTX_CT_P_SLIDE_MASTER_TEXT_STYLES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_list_style_s pptx_ct_a_text_list_style;
typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;

typedef struct pptx_ct_p_slide_master_text_styles_s pptx_ct_p_slide_master_text_styles;
pptx_ct_p_slide_master_text_styles *pptx_ct_p_slide_master_text_styles_new(xmlNode *node);
void pptx_ct_p_slide_master_text_styles_free(pptx_ct_p_slide_master_text_styles *obj);
pptx_ct_a_text_list_style *pptx_ct_p_slide_master_text_styles_get_title_style(const pptx_ct_p_slide_master_text_styles *const obj);
pptx_ct_a_text_list_style *pptx_ct_p_slide_master_text_styles_get_body_style(const pptx_ct_p_slide_master_text_styles *const obj);
pptx_ct_a_text_list_style *pptx_ct_p_slide_master_text_styles_get_other_style(const pptx_ct_p_slide_master_text_styles *const obj);
pptx_ct_p_extension_list *pptx_ct_p_slide_master_text_styles_get_ext_lst(const pptx_ct_p_slide_master_text_styles *const obj);
int32_t pptx_ct_p_slide_master_text_styles_get_index(pptx_ct_p_slide_master_text_styles *obj);

#endif /* __PPTX_CT_P_SLIDE_MASTER_TEXT_STYLES_H__ */

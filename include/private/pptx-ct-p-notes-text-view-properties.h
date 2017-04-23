#ifndef __PPTX_CT_P_NOTES_TEXT_VIEW_PROPERTIES_H__
#define __PPTX_CT_P_NOTES_TEXT_VIEW_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_common_view_properties_s pptx_ct_p_common_view_properties;
typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;

typedef struct pptx_ct_p_notes_text_view_properties_s pptx_ct_p_notes_text_view_properties;
pptx_ct_p_notes_text_view_properties *pptx_ct_p_notes_text_view_properties_new(xmlNode *node);
void pptx_ct_p_notes_text_view_properties_free(pptx_ct_p_notes_text_view_properties *obj);
pptx_ct_p_common_view_properties *pptx_ct_p_notes_text_view_properties_get_c_view_pr(const pptx_ct_p_notes_text_view_properties *const obj);
pptx_ct_p_extension_list *pptx_ct_p_notes_text_view_properties_get_ext_lst(const pptx_ct_p_notes_text_view_properties *const obj);
int32_t pptx_ct_p_notes_text_view_properties_get_index(pptx_ct_p_notes_text_view_properties *obj);

#endif /* __PPTX_CT_P_NOTES_TEXT_VIEW_PROPERTIES_H__ */

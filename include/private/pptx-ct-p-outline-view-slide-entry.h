#ifndef __PPTX_CT_P_OUTLINE_VIEW_SLIDE_ENTRY_H__
#define __PPTX_CT_P_OUTLINE_VIEW_SLIDE_ENTRY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_outline_view_slide_entry_s pptx_ct_p_outline_view_slide_entry;
pptx_ct_p_outline_view_slide_entry *pptx_ct_p_outline_view_slide_entry_new(xmlNode *node);
void pptx_ct_p_outline_view_slide_entry_free(pptx_ct_p_outline_view_slide_entry *obj);
pptx_string pptx_ct_p_outline_view_slide_entry_get_r_id(const pptx_ct_p_outline_view_slide_entry *const obj);
pptx_bool pptx_ct_p_outline_view_slide_entry_get_collapse(const pptx_ct_p_outline_view_slide_entry *const obj);
int32_t pptx_ct_p_outline_view_slide_entry_get_index(pptx_ct_p_outline_view_slide_entry *obj);

#endif /* __PPTX_CT_P_OUTLINE_VIEW_SLIDE_ENTRY_H__ */

#ifndef __PPTX_CT_P_EMBEDDED_FONT_LIST_H__
#define __PPTX_CT_P_EMBEDDED_FONT_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_embedded_font_list_entry_s pptx_ct_p_embedded_font_list_entry;

typedef struct pptx_ct_p_embedded_font_list_s pptx_ct_p_embedded_font_list;
pptx_ct_p_embedded_font_list *pptx_ct_p_embedded_font_list_new(xmlNode *node);
void pptx_ct_p_embedded_font_list_free(pptx_ct_p_embedded_font_list *obj);
pptx_ct_p_embedded_font_list_entry **pptx_ct_p_embedded_font_list_get_embedded_font(const pptx_ct_p_embedded_font_list *const obj);
int32_t pptx_ct_p_embedded_font_list_get_index(pptx_ct_p_embedded_font_list *obj);

#endif /* __PPTX_CT_P_EMBEDDED_FONT_LIST_H__ */

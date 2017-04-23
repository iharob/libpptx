#ifndef __PPTX_CT_A_CLIPBOARD_STYLE_SHEET_H__
#define __PPTX_CT_A_CLIPBOARD_STYLE_SHEET_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_base_styles_s pptx_ct_a_base_styles;
typedef struct pptx_ct_a_color_mapping_s pptx_ct_a_color_mapping;

typedef struct pptx_ct_a_clipboard_style_sheet_s pptx_ct_a_clipboard_style_sheet;
pptx_ct_a_clipboard_style_sheet *pptx_ct_a_clipboard_style_sheet_new(xmlNode *node);
void pptx_ct_a_clipboard_style_sheet_free(pptx_ct_a_clipboard_style_sheet *obj);
pptx_ct_a_base_styles *pptx_ct_a_clipboard_style_sheet_get_theme_elements(const pptx_ct_a_clipboard_style_sheet *const obj);
pptx_ct_a_color_mapping *pptx_ct_a_clipboard_style_sheet_get_clr_map(const pptx_ct_a_clipboard_style_sheet *const obj);
int32_t pptx_ct_a_clipboard_style_sheet_get_index(pptx_ct_a_clipboard_style_sheet *obj);

#endif /* __PPTX_CT_A_CLIPBOARD_STYLE_SHEET_H__ */

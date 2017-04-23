#ifndef __PPTX_CT_A_TEXT_FONT_H__
#define __PPTX_CT_A_TEXT_FONT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_pitch_family_byte_enum pptx_st_pitch_family_byte_enum;

typedef struct pptx_ct_a_text_font_s pptx_ct_a_text_font;
pptx_ct_a_text_font *pptx_ct_a_text_font_new(xmlNode *node);
void pptx_ct_a_text_font_free(pptx_ct_a_text_font *obj);
pptx_string pptx_ct_a_text_font_get_typeface(const pptx_ct_a_text_font *const obj);
pptx_hexbin pptx_ct_a_text_font_get_panose(const pptx_ct_a_text_font *const obj);
pptx_st_pitch_family_byte_enum pptx_ct_a_text_font_get_pitch_family(const pptx_ct_a_text_font *const obj);
pptx_byte pptx_ct_a_text_font_get_charset(const pptx_ct_a_text_font *const obj);
int32_t pptx_ct_a_text_font_get_index(pptx_ct_a_text_font *obj);

#endif /* __PPTX_CT_A_TEXT_FONT_H__ */

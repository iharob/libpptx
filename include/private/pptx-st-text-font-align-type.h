#ifndef __PPTX_ST_TEXT_FONT_ALIGN_TYPE_H__
#define __PPTX_ST_TEXT_FONT_ALIGN_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_text_font_align_type_token_enum {
    ST_TEXT_FONT_ALIGN_TYPE_B,
    ST_TEXT_FONT_ALIGN_TYPE_CTR,
    ST_TEXT_FONT_ALIGN_TYPE_NIL,
    ST_TEXT_FONT_ALIGN_TYPE_AUTO,
    ST_TEXT_FONT_ALIGN_TYPE_BASE,
    ST_TEXT_FONT_ALIGN_TYPE_T
} pptx_st_text_font_align_type_token_enum;

pptx_st_text_font_align_type_token_enum pptx_get_st_text_font_align_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TEXT_FONT_ALIGN_TYPE_H__ */

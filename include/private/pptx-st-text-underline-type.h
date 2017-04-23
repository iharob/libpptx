#ifndef __PPTX_ST_TEXT_UNDERLINE_TYPE_H__
#define __PPTX_ST_TEXT_UNDERLINE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_text_underline_type_token_enum {
    ST_TEXT_UNDERLINE_TYPE_HEAVY,
    ST_TEXT_UNDERLINE_TYPE_SNG,
    ST_TEXT_UNDERLINE_TYPE_NONE,
    ST_TEXT_UNDERLINE_TYPE_DOT_DOT_DASH_HEAVY,
    ST_TEXT_UNDERLINE_TYPE_DBL,
    ST_TEXT_UNDERLINE_TYPE_DOTTED,
    ST_TEXT_UNDERLINE_TYPE_DASH_HEAVY,
    ST_TEXT_UNDERLINE_TYPE_DOTTED_HEAVY,
    ST_TEXT_UNDERLINE_TYPE_DASH,
    ST_TEXT_UNDERLINE_TYPE_WAVY_DBL,
    ST_TEXT_UNDERLINE_TYPE_NIL,
    ST_TEXT_UNDERLINE_TYPE_WAVY,
    ST_TEXT_UNDERLINE_TYPE_DASH_LONG_HEAVY,
    ST_TEXT_UNDERLINE_TYPE_WORDS,
    ST_TEXT_UNDERLINE_TYPE_WAVY_HEAVY,
    ST_TEXT_UNDERLINE_TYPE_DOT_DASH_HEAVY,
    ST_TEXT_UNDERLINE_TYPE_DASH_LONG,
    ST_TEXT_UNDERLINE_TYPE_DOT_DOT_DASH,
    ST_TEXT_UNDERLINE_TYPE_DOT_DASH
} pptx_st_text_underline_type_token_enum;

pptx_st_text_underline_type_token_enum pptx_get_st_text_underline_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TEXT_UNDERLINE_TYPE_H__ */

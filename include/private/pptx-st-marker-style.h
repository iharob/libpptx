#ifndef __PPTX_ST_MARKER_STYLE_H__
#define __PPTX_ST_MARKER_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_marker_style_text_enum {
    ST_MARKER_STYLE_PICTURE,
    ST_MARKER_STYLE_NONE,
    ST_MARKER_STYLE_DIAMOND,
    ST_MARKER_STYLE_STAR,
    ST_MARKER_STYLE_NIL,
    ST_MARKER_STYLE_AUTO,
    ST_MARKER_STYLE_DASH,
    ST_MARKER_STYLE_SQUARE,
    ST_MARKER_STYLE_PLUS,
    ST_MARKER_STYLE_X,
    ST_MARKER_STYLE_TRIANGLE,
    ST_MARKER_STYLE_CIRCLE,
    ST_MARKER_STYLE_DOT
} pptx_st_marker_style_text_enum;

pptx_st_marker_style_text_enum pptx_get_st_marker_style(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_MARKER_STYLE_H__ */

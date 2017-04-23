#ifndef __PPTX_ST_WEB_COLOR_TYPE_H__
#define __PPTX_ST_WEB_COLOR_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_web_color_type_token_enum {
    ST_WEB_COLOR_TYPE_NONE,
    ST_WEB_COLOR_TYPE_NIL,
    ST_WEB_COLOR_TYPE_PRESENTATION_ACCENT,
    ST_WEB_COLOR_TYPE_PRESENTATION_TEXT,
    ST_WEB_COLOR_TYPE_WHITE_TEXT_ON_BLACK,
    ST_WEB_COLOR_TYPE_BLACK_TEXT_ON_WHITE,
    ST_WEB_COLOR_TYPE_BROWSER
} pptx_st_web_color_type_token_enum;

pptx_st_web_color_type_token_enum pptx_get_st_web_color_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_WEB_COLOR_TYPE_H__ */

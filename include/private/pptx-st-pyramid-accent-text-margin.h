#ifndef __PPTX_ST_PYRAMID_ACCENT_TEXT_MARGIN_H__
#define __PPTX_ST_PYRAMID_ACCENT_TEXT_MARGIN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_pyramid_accent_text_margin_token_enum {
    ST_PYRAMID_ACCENT_TEXT_MARGIN_STEP,
    ST_PYRAMID_ACCENT_TEXT_MARGIN_STACK,
    ST_PYRAMID_ACCENT_TEXT_MARGIN_NIL
} pptx_st_pyramid_accent_text_margin_token_enum;

pptx_st_pyramid_accent_text_margin_token_enum pptx_get_st_pyramid_accent_text_margin(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PYRAMID_ACCENT_TEXT_MARGIN_H__ */

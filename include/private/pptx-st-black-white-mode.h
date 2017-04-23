#ifndef __PPTX_ST_BLACK_WHITE_MODE_H__
#define __PPTX_ST_BLACK_WHITE_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_black_white_mode_token_enum {
    ST_BLACK_WHITE_MODE_GRAY_WHITE,
    ST_BLACK_WHITE_MODE_NIL,
    ST_BLACK_WHITE_MODE_INV_GRAY,
    ST_BLACK_WHITE_MODE_AUTO,
    ST_BLACK_WHITE_MODE_BLACK_GRAY,
    ST_BLACK_WHITE_MODE_LT_GRAY,
    ST_BLACK_WHITE_MODE_BLACK,
    ST_BLACK_WHITE_MODE_BLACK_WHITE,
    ST_BLACK_WHITE_MODE_GRAY,
    ST_BLACK_WHITE_MODE_WHITE,
    ST_BLACK_WHITE_MODE_HIDDEN,
    ST_BLACK_WHITE_MODE_CLR
} pptx_st_black_white_mode_token_enum;

pptx_st_black_white_mode_token_enum pptx_get_st_black_white_mode(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BLACK_WHITE_MODE_H__ */

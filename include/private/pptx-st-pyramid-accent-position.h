#ifndef __PPTX_ST_PYRAMID_ACCENT_POSITION_H__
#define __PPTX_ST_PYRAMID_ACCENT_POSITION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_pyramid_accent_position_token_enum {
    ST_PYRAMID_ACCENT_POSITION_AFT,
    ST_PYRAMID_ACCENT_POSITION_BEF,
    ST_PYRAMID_ACCENT_POSITION_NIL
} pptx_st_pyramid_accent_position_token_enum;

pptx_st_pyramid_accent_position_token_enum pptx_get_st_pyramid_accent_position(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PYRAMID_ACCENT_POSITION_H__ */

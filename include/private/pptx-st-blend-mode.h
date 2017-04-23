#ifndef __PPTX_ST_BLEND_MODE_H__
#define __PPTX_ST_BLEND_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_blend_mode_token_enum {
    ST_BLEND_MODE_DARKEN,
    ST_BLEND_MODE_NIL,
    ST_BLEND_MODE_OVER,
    ST_BLEND_MODE_SCREEN,
    ST_BLEND_MODE_LIGHTEN,
    ST_BLEND_MODE_MULT
} pptx_st_blend_mode_token_enum;

pptx_st_blend_mode_token_enum pptx_get_st_blend_mode(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BLEND_MODE_H__ */

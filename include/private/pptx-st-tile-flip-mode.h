#ifndef __PPTX_ST_TILE_FLIP_MODE_H__
#define __PPTX_ST_TILE_FLIP_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tile_flip_mode_token_enum {
    ST_TILE_FLIP_MODE_Y,
    ST_TILE_FLIP_MODE_X,
    ST_TILE_FLIP_MODE_NONE,
    ST_TILE_FLIP_MODE_XY,
    ST_TILE_FLIP_MODE_NIL
} pptx_st_tile_flip_mode_token_enum;

pptx_st_tile_flip_mode_token_enum pptx_get_st_tile_flip_mode(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TILE_FLIP_MODE_H__ */

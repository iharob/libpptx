#ifndef __PPTX_ST_BEVEL_PRESET_TYPE_H__
#define __PPTX_ST_BEVEL_PRESET_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_bevel_preset_type_token_enum {
    ST_BEVEL_PRESET_TYPE_SLOPE,
    ST_BEVEL_PRESET_TYPE_RIBLET,
    ST_BEVEL_PRESET_TYPE_ANGLE,
    ST_BEVEL_PRESET_TYPE_NIL,
    ST_BEVEL_PRESET_TYPE_SOFT_ROUND,
    ST_BEVEL_PRESET_TYPE_ART_DECO,
    ST_BEVEL_PRESET_TYPE_CROSS,
    ST_BEVEL_PRESET_TYPE_RELAXED_INSET,
    ST_BEVEL_PRESET_TYPE_HARD_EDGE,
    ST_BEVEL_PRESET_TYPE_CONVEX,
    ST_BEVEL_PRESET_TYPE_COOL_SLANT,
    ST_BEVEL_PRESET_TYPE_CIRCLE,
    ST_BEVEL_PRESET_TYPE_DIVOT
} pptx_st_bevel_preset_type_token_enum;

pptx_st_bevel_preset_type_token_enum pptx_get_st_bevel_preset_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BEVEL_PRESET_TYPE_H__ */

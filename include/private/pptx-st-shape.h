#ifndef __PPTX_ST_SHAPE_H__
#define __PPTX_ST_SHAPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_shape_text_enum {
    ST_SHAPE_BOX,
    ST_SHAPE_CYLINDER,
    ST_SHAPE_PYRAMID,
    ST_SHAPE_NIL,
    ST_SHAPE_CONE_TO_MAX,
    ST_SHAPE_PYRAMID_TO_MAX,
    ST_SHAPE_CONE
} pptx_st_shape_text_enum;

pptx_st_shape_text_enum pptx_get_st_shape(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SHAPE_H__ */

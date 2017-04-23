#ifndef __PPTX_ST_TRANSITION_CORNER_DIRECTION_TYPE_H__
#define __PPTX_ST_TRANSITION_CORNER_DIRECTION_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_transition_corner_direction_type_token_enum {
    ST_TRANSITION_CORNER_DIRECTION_TYPE_RD,
    ST_TRANSITION_CORNER_DIRECTION_TYPE_RU,
    ST_TRANSITION_CORNER_DIRECTION_TYPE_LD,
    ST_TRANSITION_CORNER_DIRECTION_TYPE_LU,
    ST_TRANSITION_CORNER_DIRECTION_TYPE_NIL
} pptx_st_transition_corner_direction_type_token_enum;

pptx_st_transition_corner_direction_type_token_enum pptx_get_st_transition_corner_direction_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TRANSITION_CORNER_DIRECTION_TYPE_H__ */

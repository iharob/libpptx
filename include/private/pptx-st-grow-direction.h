#ifndef __PPTX_ST_GROW_DIRECTION_H__
#define __PPTX_ST_GROW_DIRECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_grow_direction_token_enum {
    ST_GROW_DIRECTION_B_L,
    ST_GROW_DIRECTION_T_L,
    ST_GROW_DIRECTION_T_R,
    ST_GROW_DIRECTION_NIL,
    ST_GROW_DIRECTION_B_R
} pptx_st_grow_direction_token_enum;

pptx_st_grow_direction_token_enum pptx_get_st_grow_direction(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_GROW_DIRECTION_H__ */

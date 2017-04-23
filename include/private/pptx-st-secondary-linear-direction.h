#ifndef __PPTX_ST_SECONDARY_LINEAR_DIRECTION_H__
#define __PPTX_ST_SECONDARY_LINEAR_DIRECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_secondary_linear_direction_token_enum {
    ST_SECONDARY_LINEAR_DIRECTION_NONE,
    ST_SECONDARY_LINEAR_DIRECTION_NIL,
    ST_SECONDARY_LINEAR_DIRECTION_FROM_B,
    ST_SECONDARY_LINEAR_DIRECTION_FROM_L,
    ST_SECONDARY_LINEAR_DIRECTION_FROM_T,
    ST_SECONDARY_LINEAR_DIRECTION_FROM_R
} pptx_st_secondary_linear_direction_token_enum;

pptx_st_secondary_linear_direction_token_enum pptx_get_st_secondary_linear_direction(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SECONDARY_LINEAR_DIRECTION_H__ */

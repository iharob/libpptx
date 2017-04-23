#ifndef __PPTX_ST_DIRECTION_H__
#define __PPTX_ST_DIRECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_direction_token_enum {
    ST_DIRECTION_HORZ,
    ST_DIRECTION_VERT,
    ST_DIRECTION_NIL
} pptx_st_direction_token_enum;

pptx_st_direction_token_enum pptx_get_st_direction(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_DIRECTION_H__ */

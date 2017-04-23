#ifndef __PPTX_ST_CONTINUE_DIRECTION_H__
#define __PPTX_ST_CONTINUE_DIRECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_continue_direction_token_enum {
    ST_CONTINUE_DIRECTION_SAME_DIR,
    ST_CONTINUE_DIRECTION_REV_DIR,
    ST_CONTINUE_DIRECTION_NIL
} pptx_st_continue_direction_token_enum;

pptx_st_continue_direction_token_enum pptx_get_st_continue_direction(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CONTINUE_DIRECTION_H__ */

#ifndef __PPTX_ST_FLOW_DIRECTION_H__
#define __PPTX_ST_FLOW_DIRECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_flow_direction_token_enum {
    ST_FLOW_DIRECTION_COL,
    ST_FLOW_DIRECTION_NIL,
    ST_FLOW_DIRECTION_ROW
} pptx_st_flow_direction_token_enum;

pptx_st_flow_direction_token_enum pptx_get_st_flow_direction(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_FLOW_DIRECTION_H__ */

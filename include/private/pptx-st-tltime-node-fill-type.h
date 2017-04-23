#ifndef __PPTX_ST_TLTIME_NODE_FILL_TYPE_H__
#define __PPTX_ST_TLTIME_NODE_FILL_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltime_node_fill_type_token_enum {
    ST_TLTIME_NODE_FILL_TYPE_TRANSITION,
    ST_TLTIME_NODE_FILL_TYPE_HOLD,
    ST_TLTIME_NODE_FILL_TYPE_NIL,
    ST_TLTIME_NODE_FILL_TYPE_REMOVE,
    ST_TLTIME_NODE_FILL_TYPE_FREEZE
} pptx_st_tltime_node_fill_type_token_enum;

pptx_st_tltime_node_fill_type_token_enum pptx_get_st_tltime_node_fill_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLTIME_NODE_FILL_TYPE_H__ */

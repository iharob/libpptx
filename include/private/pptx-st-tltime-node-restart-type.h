#ifndef __PPTX_ST_TLTIME_NODE_RESTART_TYPE_H__
#define __PPTX_ST_TLTIME_NODE_RESTART_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltime_node_restart_type_token_enum {
    ST_TLTIME_NODE_RESTART_TYPE_ALWAYS,
    ST_TLTIME_NODE_RESTART_TYPE_NEVER,
    ST_TLTIME_NODE_RESTART_TYPE_WHEN_NOT_ACTIVE,
    ST_TLTIME_NODE_RESTART_TYPE_NIL
} pptx_st_tltime_node_restart_type_token_enum;

pptx_st_tltime_node_restart_type_token_enum pptx_get_st_tltime_node_restart_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLTIME_NODE_RESTART_TYPE_H__ */

#ifndef __PPTX_ST_TLTRIGGER_RUNTIME_NODE_H__
#define __PPTX_ST_TLTRIGGER_RUNTIME_NODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltrigger_runtime_node_token_enum {
    ST_TLTRIGGER_RUNTIME_NODE_ALL,
    ST_TLTRIGGER_RUNTIME_NODE_LAST,
    ST_TLTRIGGER_RUNTIME_NODE_NIL,
    ST_TLTRIGGER_RUNTIME_NODE_FIRST
} pptx_st_tltrigger_runtime_node_token_enum;

pptx_st_tltrigger_runtime_node_token_enum pptx_get_st_tltrigger_runtime_node(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLTRIGGER_RUNTIME_NODE_H__ */

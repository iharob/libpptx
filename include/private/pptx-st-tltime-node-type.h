#ifndef __PPTX_ST_TLTIME_NODE_TYPE_H__
#define __PPTX_ST_TLTIME_NODE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltime_node_type_token_enum {
    ST_TLTIME_NODE_TYPE_CLICK_PAR,
    ST_TLTIME_NODE_TYPE_NIL,
    ST_TLTIME_NODE_TYPE_AFTER_EFFECT,
    ST_TLTIME_NODE_TYPE_INTERACTIVE_SEQ,
    ST_TLTIME_NODE_TYPE_CLICK_EFFECT,
    ST_TLTIME_NODE_TYPE_WITH_EFFECT,
    ST_TLTIME_NODE_TYPE_WITH_GROUP,
    ST_TLTIME_NODE_TYPE_TM_ROOT,
    ST_TLTIME_NODE_TYPE_AFTER_GROUP,
    ST_TLTIME_NODE_TYPE_MAIN_SEQ
} pptx_st_tltime_node_type_token_enum;

pptx_st_tltime_node_type_token_enum pptx_get_st_tltime_node_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLTIME_NODE_TYPE_H__ */

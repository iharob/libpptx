#ifndef __PPTX_ST_TLTIME_NODE_MASTER_RELATION_H__
#define __PPTX_ST_TLTIME_NODE_MASTER_RELATION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltime_node_master_relation_token_enum {
    ST_TLTIME_NODE_MASTER_RELATION_NEXT_CLICK,
    ST_TLTIME_NODE_MASTER_RELATION_LAST_CLICK,
    ST_TLTIME_NODE_MASTER_RELATION_SAME_CLICK,
    ST_TLTIME_NODE_MASTER_RELATION_NIL
} pptx_st_tltime_node_master_relation_token_enum;

pptx_st_tltime_node_master_relation_token_enum pptx_get_st_tltime_node_master_relation(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLTIME_NODE_MASTER_RELATION_H__ */

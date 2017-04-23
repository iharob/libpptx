#ifndef __PPTX_ST_NODE_VERTICAL_ALIGNMENT_H__
#define __PPTX_ST_NODE_VERTICAL_ALIGNMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_node_vertical_alignment_token_enum {
    ST_NODE_VERTICAL_ALIGNMENT_B,
    ST_NODE_VERTICAL_ALIGNMENT_T,
    ST_NODE_VERTICAL_ALIGNMENT_NIL,
    ST_NODE_VERTICAL_ALIGNMENT_MID
} pptx_st_node_vertical_alignment_token_enum;

pptx_st_node_vertical_alignment_token_enum pptx_get_st_node_vertical_alignment(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_NODE_VERTICAL_ALIGNMENT_H__ */

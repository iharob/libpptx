#ifndef __PPTX_ST_CONNECTOR_ROUTING_H__
#define __PPTX_ST_CONNECTOR_ROUTING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_connector_routing_token_enum {
    ST_CONNECTOR_ROUTING_LONG_CURVE,
    ST_CONNECTOR_ROUTING_STRA,
    ST_CONNECTOR_ROUTING_CURVE,
    ST_CONNECTOR_ROUTING_BEND,
    ST_CONNECTOR_ROUTING_NIL
} pptx_st_connector_routing_token_enum;

pptx_st_connector_routing_token_enum pptx_get_st_connector_routing(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CONNECTOR_ROUTING_H__ */

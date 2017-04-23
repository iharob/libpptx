#ifndef __PPTX_ST_CONNECTOR_DIMENSION_H__
#define __PPTX_ST_CONNECTOR_DIMENSION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_connector_dimension_token_enum {
    ST_CONNECTOR_DIMENSION__2D,
    ST_CONNECTOR_DIMENSION_1_D,
    ST_CONNECTOR_DIMENSION_NIL,
    ST_CONNECTOR_DIMENSION_CUST
} pptx_st_connector_dimension_token_enum;

pptx_st_connector_dimension_token_enum pptx_get_st_connector_dimension(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CONNECTOR_DIMENSION_H__ */

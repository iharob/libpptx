#ifndef __PPTX_ST_CONNECTOR_POINT_H__
#define __PPTX_ST_CONNECTOR_POINT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_connector_point_token_enum {
    ST_CONNECTOR_POINT_MID_L,
    ST_CONNECTOR_POINT_NIL,
    ST_CONNECTOR_POINT_CTR,
    ST_CONNECTOR_POINT_B_CTR,
    ST_CONNECTOR_POINT_B_L,
    ST_CONNECTOR_POINT_AUTO,
    ST_CONNECTOR_POINT_T_R,
    ST_CONNECTOR_POINT_T_CTR,
    ST_CONNECTOR_POINT_T_L,
    ST_CONNECTOR_POINT_B_R,
    ST_CONNECTOR_POINT_RADIAL,
    ST_CONNECTOR_POINT_MID_R
} pptx_st_connector_point_token_enum;

pptx_st_connector_point_token_enum pptx_get_st_connector_point(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CONNECTOR_POINT_H__ */

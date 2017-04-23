#ifndef __PPTX_ST_CENTER_SHAPE_MAPPING_H__
#define __PPTX_ST_CENTER_SHAPE_MAPPING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_center_shape_mapping_token_enum {
    ST_CENTER_SHAPE_MAPPING_NONE,
    ST_CENTER_SHAPE_MAPPING_NIL,
    ST_CENTER_SHAPE_MAPPING_F_NODE
} pptx_st_center_shape_mapping_token_enum;

pptx_st_center_shape_mapping_token_enum pptx_get_st_center_shape_mapping(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CENTER_SHAPE_MAPPING_H__ */

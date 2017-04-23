#ifndef __PPTX_ST_BEND_POINT_H__
#define __PPTX_ST_BEND_POINT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_bend_point_token_enum {
    ST_BEND_POINT_NIL,
    ST_BEND_POINT_END,
    ST_BEND_POINT_BEG,
    ST_BEND_POINT_DEF
} pptx_st_bend_point_token_enum;

pptx_st_bend_point_token_enum pptx_get_st_bend_point(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BEND_POINT_H__ */

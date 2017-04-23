#ifndef __PPTX_ST_TRENDLINE_TYPE_H__
#define __PPTX_ST_TRENDLINE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_trendline_type_text_enum {
    ST_TRENDLINE_TYPE_LINEAR,
    ST_TRENDLINE_TYPE_POWER,
    ST_TRENDLINE_TYPE_NIL,
    ST_TRENDLINE_TYPE_POLY,
    ST_TRENDLINE_TYPE_EXP,
    ST_TRENDLINE_TYPE_MOVING_AVG,
    ST_TRENDLINE_TYPE_LOG
} pptx_st_trendline_type_text_enum;

pptx_st_trendline_type_text_enum pptx_get_st_trendline_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TRENDLINE_TYPE_H__ */

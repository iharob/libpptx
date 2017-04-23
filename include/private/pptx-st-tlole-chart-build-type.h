#ifndef __PPTX_ST_TLOLE_CHART_BUILD_TYPE_H__
#define __PPTX_ST_TLOLE_CHART_BUILD_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlole_chart_build_type_token_enum {
    ST_TLOLE_CHART_BUILD_TYPE_CATEGORY,
    ST_TLOLE_CHART_BUILD_TYPE_NIL,
    ST_TLOLE_CHART_BUILD_TYPE_ALL_AT_ONCE,
    ST_TLOLE_CHART_BUILD_TYPE_SERIES,
    ST_TLOLE_CHART_BUILD_TYPE_CATEGORY_EL,
    ST_TLOLE_CHART_BUILD_TYPE_SERIES_EL
} pptx_st_tlole_chart_build_type_token_enum;

pptx_st_tlole_chart_build_type_token_enum pptx_get_st_tlole_chart_build_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLOLE_CHART_BUILD_TYPE_H__ */

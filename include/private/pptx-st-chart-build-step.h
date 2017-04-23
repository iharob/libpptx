#ifndef __PPTX_ST_CHART_BUILD_STEP_H__
#define __PPTX_ST_CHART_BUILD_STEP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_chart_build_step_token_enum {
    ST_CHART_BUILD_STEP_CATEGORY,
    ST_CHART_BUILD_STEP_PT_IN_CATEGORY,
    ST_CHART_BUILD_STEP_NIL,
    ST_CHART_BUILD_STEP_GRID_LEGEND,
    ST_CHART_BUILD_STEP_SERIES,
    ST_CHART_BUILD_STEP_ALL_PTS,
    ST_CHART_BUILD_STEP_PT_IN_SERIES
} pptx_st_chart_build_step_token_enum;

pptx_st_chart_build_step_token_enum pptx_get_st_chart_build_step(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CHART_BUILD_STEP_H__ */

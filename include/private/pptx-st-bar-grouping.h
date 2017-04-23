#ifndef __PPTX_ST_BAR_GROUPING_H__
#define __PPTX_ST_BAR_GROUPING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_bar_grouping_text_enum {
    ST_BAR_GROUPING_PERCENT_STACKED,
    ST_BAR_GROUPING_CLUSTERED,
    ST_BAR_GROUPING_STACKED,
    ST_BAR_GROUPING_NIL,
    ST_BAR_GROUPING_STANDARD
} pptx_st_bar_grouping_text_enum;

pptx_st_bar_grouping_text_enum pptx_get_st_bar_grouping(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BAR_GROUPING_H__ */

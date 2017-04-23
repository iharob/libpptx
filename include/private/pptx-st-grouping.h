#ifndef __PPTX_ST_GROUPING_H__
#define __PPTX_ST_GROUPING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_grouping_text_enum {
    ST_GROUPING_PERCENT_STACKED,
    ST_GROUPING_STACKED,
    ST_GROUPING_NIL,
    ST_GROUPING_STANDARD
} pptx_st_grouping_text_enum;

pptx_st_grouping_text_enum pptx_get_st_grouping(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_GROUPING_H__ */

#ifndef __PPTX_ST_TLCHART_SUBELEMENT_TYPE_H__
#define __PPTX_ST_TLCHART_SUBELEMENT_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlchart_subelement_type_token_enum {
    ST_TLCHART_SUBELEMENT_TYPE_CATEGORY,
    ST_TLCHART_SUBELEMENT_TYPE_GRID_LEGEND,
    ST_TLCHART_SUBELEMENT_TYPE_NIL,
    ST_TLCHART_SUBELEMENT_TYPE_PT_IN_CATEGORY,
    ST_TLCHART_SUBELEMENT_TYPE_SERIES,
    ST_TLCHART_SUBELEMENT_TYPE_PT_IN_SERIES
} pptx_st_tlchart_subelement_type_token_enum;

pptx_st_tlchart_subelement_type_token_enum pptx_get_st_tlchart_subelement_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLCHART_SUBELEMENT_TYPE_H__ */

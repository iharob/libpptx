#ifndef __PPTX_ST_TIME_UNIT_H__
#define __PPTX_ST_TIME_UNIT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_time_unit_text_enum {
    ST_TIME_UNIT_MONTHS,
    ST_TIME_UNIT_DAYS,
    ST_TIME_UNIT_NIL,
    ST_TIME_UNIT_YEARS
} pptx_st_time_unit_text_enum;

pptx_st_time_unit_text_enum pptx_get_st_time_unit(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TIME_UNIT_H__ */

#ifndef __PPTX_ST_CALENDAR_TYPE_H__
#define __PPTX_ST_CALENDAR_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_calendar_type_text_enum {
    ST_CALENDAR_TYPE_NONE,
    ST_CALENDAR_TYPE_KOREA,
    ST_CALENDAR_TYPE_NIL,
    ST_CALENDAR_TYPE_HIJRI,
    ST_CALENDAR_TYPE_GREGORIAN_ARABIC,
    ST_CALENDAR_TYPE_SAKA,
    ST_CALENDAR_TYPE_GREGORIAN_XLIT_ENGLISH,
    ST_CALENDAR_TYPE_GREGORIAN_ME_FRENCH,
    ST_CALENDAR_TYPE_GREGORIAN_XLIT_FRENCH,
    ST_CALENDAR_TYPE_GREGORIAN,
    ST_CALENDAR_TYPE_HEBREW,
    ST_CALENDAR_TYPE_JAPAN,
    ST_CALENDAR_TYPE_TAIWAN,
    ST_CALENDAR_TYPE_GREGORIAN_US,
    ST_CALENDAR_TYPE_THAI
} pptx_st_calendar_type_text_enum;

pptx_st_calendar_type_text_enum pptx_get_st_calendar_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CALENDAR_TYPE_H__ */

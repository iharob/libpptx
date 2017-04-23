#ifndef __PPTX_ST_TICK_MARK_H__
#define __PPTX_ST_TICK_MARK_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tick_mark_text_enum {
    ST_TICK_MARK_NONE,
    ST_TICK_MARK_OUT,
    ST_TICK_MARK_CROSS,
    ST_TICK_MARK_NIL,
    ST_TICK_MARK_IN
} pptx_st_tick_mark_text_enum;

pptx_st_tick_mark_text_enum pptx_get_st_tick_mark(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TICK_MARK_H__ */

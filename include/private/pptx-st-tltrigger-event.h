#ifndef __PPTX_ST_TLTRIGGER_EVENT_H__
#define __PPTX_ST_TLTRIGGER_EVENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltrigger_event_token_enum {
    ST_TLTRIGGER_EVENT_BEGIN,
    ST_TLTRIGGER_EVENT_END,
    ST_TLTRIGGER_EVENT_NIL,
    ST_TLTRIGGER_EVENT_ON_MOUSE_OUT,
    ST_TLTRIGGER_EVENT_ON_NEXT,
    ST_TLTRIGGER_EVENT_ON_BEGIN,
    ST_TLTRIGGER_EVENT_ON_STOP_AUDIO,
    ST_TLTRIGGER_EVENT_ON_MOUSE_OVER,
    ST_TLTRIGGER_EVENT_ON_CLICK,
    ST_TLTRIGGER_EVENT_ON_PREV,
    ST_TLTRIGGER_EVENT_ON_DBL_CLICK,
    ST_TLTRIGGER_EVENT_ON_END
} pptx_st_tltrigger_event_token_enum;

pptx_st_tltrigger_event_token_enum pptx_get_st_tltrigger_event(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLTRIGGER_EVENT_H__ */

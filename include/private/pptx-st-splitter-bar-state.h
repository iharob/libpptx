#ifndef __PPTX_ST_SPLITTER_BAR_STATE_H__
#define __PPTX_ST_SPLITTER_BAR_STATE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_splitter_bar_state_token_enum {
    ST_SPLITTER_BAR_STATE_NIL,
    ST_SPLITTER_BAR_STATE_MINIMIZED,
    ST_SPLITTER_BAR_STATE_RESTORED,
    ST_SPLITTER_BAR_STATE_MAXIMIZED
} pptx_st_splitter_bar_state_token_enum;

pptx_st_splitter_bar_state_token_enum pptx_get_st_splitter_bar_state(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SPLITTER_BAR_STATE_H__ */

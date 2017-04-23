#ifndef __PPTX_ST_TLPREVIOUS_ACTION_TYPE_H__
#define __PPTX_ST_TLPREVIOUS_ACTION_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlprevious_action_type_token_enum {
    ST_TLPREVIOUS_ACTION_TYPE_NONE,
    ST_TLPREVIOUS_ACTION_TYPE_SKIP_TIMED,
    ST_TLPREVIOUS_ACTION_TYPE_NIL
} pptx_st_tlprevious_action_type_token_enum;

pptx_st_tlprevious_action_type_token_enum pptx_get_st_tlprevious_action_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLPREVIOUS_ACTION_TYPE_H__ */

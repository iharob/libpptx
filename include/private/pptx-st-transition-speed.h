#ifndef __PPTX_ST_TRANSITION_SPEED_H__
#define __PPTX_ST_TRANSITION_SPEED_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_transition_speed_token_enum {
    ST_TRANSITION_SPEED_MED,
    ST_TRANSITION_SPEED_SLOW,
    ST_TRANSITION_SPEED_NIL,
    ST_TRANSITION_SPEED_FAST
} pptx_st_transition_speed_token_enum;

pptx_st_transition_speed_token_enum pptx_get_st_transition_speed(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TRANSITION_SPEED_H__ */

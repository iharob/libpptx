#ifndef __PPTX_ST_TRANSITION_IN_OUT_DIRECTION_TYPE_H__
#define __PPTX_ST_TRANSITION_IN_OUT_DIRECTION_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_transition_in_out_direction_type_token_enum {
    ST_TRANSITION_IN_OUT_DIRECTION_TYPE_IN,
    ST_TRANSITION_IN_OUT_DIRECTION_TYPE_NIL,
    ST_TRANSITION_IN_OUT_DIRECTION_TYPE_OUT
} pptx_st_transition_in_out_direction_type_token_enum;

pptx_st_transition_in_out_direction_type_token_enum pptx_get_st_transition_in_out_direction_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TRANSITION_IN_OUT_DIRECTION_TYPE_H__ */

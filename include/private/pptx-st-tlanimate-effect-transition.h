#ifndef __PPTX_ST_TLANIMATE_EFFECT_TRANSITION_H__
#define __PPTX_ST_TLANIMATE_EFFECT_TRANSITION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlanimate_effect_transition_token_enum {
    ST_TLANIMATE_EFFECT_TRANSITION_NONE,
    ST_TLANIMATE_EFFECT_TRANSITION_OUT,
    ST_TLANIMATE_EFFECT_TRANSITION_NIL,
    ST_TLANIMATE_EFFECT_TRANSITION_IN
} pptx_st_tlanimate_effect_transition_token_enum;

pptx_st_tlanimate_effect_transition_token_enum pptx_get_st_tlanimate_effect_transition(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLANIMATE_EFFECT_TRANSITION_H__ */

#ifndef __PPTX_ST_TLANIMATE_BEHAVIOR_CALC_MODE_H__
#define __PPTX_ST_TLANIMATE_BEHAVIOR_CALC_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlanimate_behavior_calc_mode_token_enum {
    ST_TLANIMATE_BEHAVIOR_CALC_MODE_DISCRETE,
    ST_TLANIMATE_BEHAVIOR_CALC_MODE_LIN,
    ST_TLANIMATE_BEHAVIOR_CALC_MODE_NIL,
    ST_TLANIMATE_BEHAVIOR_CALC_MODE_FMLA
} pptx_st_tlanimate_behavior_calc_mode_token_enum;

pptx_st_tlanimate_behavior_calc_mode_token_enum pptx_get_st_tlanimate_behavior_calc_mode(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLANIMATE_BEHAVIOR_CALC_MODE_H__ */

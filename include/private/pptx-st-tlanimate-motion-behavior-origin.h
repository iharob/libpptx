#ifndef __PPTX_ST_TLANIMATE_MOTION_BEHAVIOR_ORIGIN_H__
#define __PPTX_ST_TLANIMATE_MOTION_BEHAVIOR_ORIGIN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlanimate_motion_behavior_origin_token_enum {
    ST_TLANIMATE_MOTION_BEHAVIOR_ORIGIN_LAYOUT,
    ST_TLANIMATE_MOTION_BEHAVIOR_ORIGIN_NIL,
    ST_TLANIMATE_MOTION_BEHAVIOR_ORIGIN_PARENT
} pptx_st_tlanimate_motion_behavior_origin_token_enum;

pptx_st_tlanimate_motion_behavior_origin_token_enum pptx_get_st_tlanimate_motion_behavior_origin(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLANIMATE_MOTION_BEHAVIOR_ORIGIN_H__ */

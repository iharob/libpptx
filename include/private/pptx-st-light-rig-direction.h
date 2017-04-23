#ifndef __PPTX_ST_LIGHT_RIG_DIRECTION_H__
#define __PPTX_ST_LIGHT_RIG_DIRECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_light_rig_direction_token_enum {
    ST_LIGHT_RIG_DIRECTION_B,
    ST_LIGHT_RIG_DIRECTION_NIL,
    ST_LIGHT_RIG_DIRECTION_BL,
    ST_LIGHT_RIG_DIRECTION_TR,
    ST_LIGHT_RIG_DIRECTION_L,
    ST_LIGHT_RIG_DIRECTION_TL,
    ST_LIGHT_RIG_DIRECTION_R,
    ST_LIGHT_RIG_DIRECTION_T,
    ST_LIGHT_RIG_DIRECTION_BR
} pptx_st_light_rig_direction_token_enum;

pptx_st_light_rig_direction_token_enum pptx_get_st_light_rig_direction(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_LIGHT_RIG_DIRECTION_H__ */

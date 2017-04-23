#ifndef __PPTX_ST_TLANIMATE_COLOR_DIRECTION_H__
#define __PPTX_ST_TLANIMATE_COLOR_DIRECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlanimate_color_direction_token_enum {
    ST_TLANIMATE_COLOR_DIRECTION_CCW,
    ST_TLANIMATE_COLOR_DIRECTION_CW,
    ST_TLANIMATE_COLOR_DIRECTION_NIL
} pptx_st_tlanimate_color_direction_token_enum;

pptx_st_tlanimate_color_direction_token_enum pptx_get_st_tlanimate_color_direction(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLANIMATE_COLOR_DIRECTION_H__ */

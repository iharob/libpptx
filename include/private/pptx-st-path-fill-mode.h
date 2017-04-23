#ifndef __PPTX_ST_PATH_FILL_MODE_H__
#define __PPTX_ST_PATH_FILL_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_path_fill_mode_token_enum {
    ST_PATH_FILL_MODE_NONE,
    ST_PATH_FILL_MODE_DARKEN,
    ST_PATH_FILL_MODE_LIGHTEN_LESS,
    ST_PATH_FILL_MODE_NIL,
    ST_PATH_FILL_MODE_LIGHTEN,
    ST_PATH_FILL_MODE_DARKEN_LESS,
    ST_PATH_FILL_MODE_NORM
} pptx_st_path_fill_mode_token_enum;

pptx_st_path_fill_mode_token_enum pptx_get_st_path_fill_mode(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PATH_FILL_MODE_H__ */

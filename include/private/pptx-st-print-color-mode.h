#ifndef __PPTX_ST_PRINT_COLOR_MODE_H__
#define __PPTX_ST_PRINT_COLOR_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_print_color_mode_token_enum {
    ST_PRINT_COLOR_MODE_GRAY,
    ST_PRINT_COLOR_MODE_BW,
    ST_PRINT_COLOR_MODE_NIL,
    ST_PRINT_COLOR_MODE_CLR
} pptx_st_print_color_mode_token_enum;

pptx_st_print_color_mode_token_enum pptx_get_st_print_color_mode(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PRINT_COLOR_MODE_H__ */

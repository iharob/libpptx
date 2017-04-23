#ifndef __PPTX_ST_SCHEME_COLOR_VAL_H__
#define __PPTX_ST_SCHEME_COLOR_VAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_scheme_color_val_token_enum {
    ST_SCHEME_COLOR_VAL_LT2,
    ST_SCHEME_COLOR_VAL_LT1,
    ST_SCHEME_COLOR_VAL_DK2,
    ST_SCHEME_COLOR_VAL_NIL,
    ST_SCHEME_COLOR_VAL_DK1,
    ST_SCHEME_COLOR_VAL_ACCENT1,
    ST_SCHEME_COLOR_VAL_ACCENT3,
    ST_SCHEME_COLOR_VAL_ACCENT2,
    ST_SCHEME_COLOR_VAL_ACCENT5,
    ST_SCHEME_COLOR_VAL_ACCENT4,
    ST_SCHEME_COLOR_VAL_ACCENT6,
    ST_SCHEME_COLOR_VAL_PH_CLR,
    ST_SCHEME_COLOR_VAL_BG1,
    ST_SCHEME_COLOR_VAL_BG2,
    ST_SCHEME_COLOR_VAL_FOL_HLINK,
    ST_SCHEME_COLOR_VAL_HLINK,
    ST_SCHEME_COLOR_VAL_TX2,
    ST_SCHEME_COLOR_VAL_TX1
} pptx_st_scheme_color_val_token_enum;

pptx_st_scheme_color_val_token_enum pptx_get_st_scheme_color_val(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SCHEME_COLOR_VAL_H__ */

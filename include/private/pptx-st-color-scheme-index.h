#ifndef __PPTX_ST_COLOR_SCHEME_INDEX_H__
#define __PPTX_ST_COLOR_SCHEME_INDEX_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_color_scheme_index_token_enum {
    ST_COLOR_SCHEME_INDEX_LT2,
    ST_COLOR_SCHEME_INDEX_LT1,
    ST_COLOR_SCHEME_INDEX_DK2,
    ST_COLOR_SCHEME_INDEX_NIL,
    ST_COLOR_SCHEME_INDEX_DK1,
    ST_COLOR_SCHEME_INDEX_ACCENT1,
    ST_COLOR_SCHEME_INDEX_ACCENT3,
    ST_COLOR_SCHEME_INDEX_ACCENT2,
    ST_COLOR_SCHEME_INDEX_ACCENT5,
    ST_COLOR_SCHEME_INDEX_ACCENT4,
    ST_COLOR_SCHEME_INDEX_ACCENT6,
    ST_COLOR_SCHEME_INDEX_HLINK,
    ST_COLOR_SCHEME_INDEX_FOL_HLINK
} pptx_st_color_scheme_index_token_enum;

pptx_st_color_scheme_index_token_enum pptx_get_st_color_scheme_index(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_COLOR_SCHEME_INDEX_H__ */

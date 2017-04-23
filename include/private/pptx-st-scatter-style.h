#ifndef __PPTX_ST_SCATTER_STYLE_H__
#define __PPTX_ST_SCATTER_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_scatter_style_text_enum {
    ST_SCATTER_STYLE_SMOOTH_MARKER,
    ST_SCATTER_STYLE_NONE,
    ST_SCATTER_STYLE_NIL,
    ST_SCATTER_STYLE_SMOOTH,
    ST_SCATTER_STYLE_MARKER,
    ST_SCATTER_STYLE_LINE_MARKER,
    ST_SCATTER_STYLE_LINE
} pptx_st_scatter_style_text_enum;

pptx_st_scatter_style_text_enum pptx_get_st_scatter_style(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SCATTER_STYLE_H__ */

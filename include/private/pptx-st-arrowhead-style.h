#ifndef __PPTX_ST_ARROWHEAD_STYLE_H__
#define __PPTX_ST_ARROWHEAD_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_arrowhead_style_token_enum {
    ST_ARROWHEAD_STYLE_AUTO,
    ST_ARROWHEAD_STYLE_ARR,
    ST_ARROWHEAD_STYLE_NIL,
    ST_ARROWHEAD_STYLE_NO_ARR
} pptx_st_arrowhead_style_token_enum;

pptx_st_arrowhead_style_token_enum pptx_get_st_arrowhead_style(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ARROWHEAD_STYLE_H__ */

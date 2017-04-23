#ifndef __PPTX_ST_COMPOUND_LINE_H__
#define __PPTX_ST_COMPOUND_LINE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_compound_line_token_enum {
    ST_COMPOUND_LINE_TRI,
    ST_COMPOUND_LINE_SNG,
    ST_COMPOUND_LINE_DBL,
    ST_COMPOUND_LINE_NIL,
    ST_COMPOUND_LINE_THIN_THICK,
    ST_COMPOUND_LINE_THICK_THIN
} pptx_st_compound_line_token_enum;

pptx_st_compound_line_token_enum pptx_get_st_compound_line(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_COMPOUND_LINE_H__ */

#ifndef __PPTX_ST_LINE_END_TYPE_H__
#define __PPTX_ST_LINE_END_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_line_end_type_token_enum {
    ST_LINE_END_TYPE_NONE,
    ST_LINE_END_TYPE_DIAMOND,
    ST_LINE_END_TYPE_TRIANGLE,
    ST_LINE_END_TYPE_NIL,
    ST_LINE_END_TYPE_STEALTH,
    ST_LINE_END_TYPE_ARROW,
    ST_LINE_END_TYPE_OVAL
} pptx_st_line_end_type_token_enum;

pptx_st_line_end_type_token_enum pptx_get_st_line_end_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_LINE_END_TYPE_H__ */

#ifndef __PPTX_ST_LINE_END_LENGTH_H__
#define __PPTX_ST_LINE_END_LENGTH_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_line_end_length_token_enum {
    ST_LINE_END_LENGTH_MED,
    ST_LINE_END_LENGTH_NIL,
    ST_LINE_END_LENGTH_SM,
    ST_LINE_END_LENGTH_LG
} pptx_st_line_end_length_token_enum;

pptx_st_line_end_length_token_enum pptx_get_st_line_end_length(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_LINE_END_LENGTH_H__ */

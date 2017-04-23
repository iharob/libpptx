#ifndef __PPTX_ST_LINE_CAP_H__
#define __PPTX_ST_LINE_CAP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_line_cap_token_enum {
    ST_LINE_CAP_FLAT,
    ST_LINE_CAP_SQ,
    ST_LINE_CAP_NIL,
    ST_LINE_CAP_RND
} pptx_st_line_cap_token_enum;

pptx_st_line_cap_token_enum pptx_get_st_line_cap(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_LINE_CAP_H__ */

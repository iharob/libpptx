#ifndef __PPTX_ST_BREAKPOINT_H__
#define __PPTX_ST_BREAKPOINT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_breakpoint_token_enum {
    ST_BREAKPOINT_BAL,
    ST_BREAKPOINT_FIXED,
    ST_BREAKPOINT_END_CNV,
    ST_BREAKPOINT_NIL
} pptx_st_breakpoint_token_enum;

pptx_st_breakpoint_token_enum pptx_get_st_breakpoint(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BREAKPOINT_H__ */

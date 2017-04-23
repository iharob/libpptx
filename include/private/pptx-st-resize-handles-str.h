#ifndef __PPTX_ST_RESIZE_HANDLES_STR_H__
#define __PPTX_ST_RESIZE_HANDLES_STR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_resize_handles_str_token_enum {
    ST_RESIZE_HANDLES_STR_EXACT,
    ST_RESIZE_HANDLES_STR_NIL,
    ST_RESIZE_HANDLES_STR_REL
} pptx_st_resize_handles_str_token_enum;

pptx_st_resize_handles_str_token_enum pptx_get_st_resize_handles_str(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_RESIZE_HANDLES_STR_H__ */

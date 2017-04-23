#ifndef __PPTX_ST_PLACEHOLDER_SIZE_H__
#define __PPTX_ST_PLACEHOLDER_SIZE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_placeholder_size_token_enum {
    ST_PLACEHOLDER_SIZE_QUARTER,
    ST_PLACEHOLDER_SIZE_FULL,
    ST_PLACEHOLDER_SIZE_NIL,
    ST_PLACEHOLDER_SIZE_HALF
} pptx_st_placeholder_size_token_enum;

pptx_st_placeholder_size_token_enum pptx_get_st_placeholder_size(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PLACEHOLDER_SIZE_H__ */

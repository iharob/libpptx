#ifndef __PPTX_ST_FUNCTION_TYPE_H__
#define __PPTX_ST_FUNCTION_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_function_type_token_enum {
    ST_FUNCTION_TYPE_CNT,
    ST_FUNCTION_TYPE_POS_ODD,
    ST_FUNCTION_TYPE_NIL,
    ST_FUNCTION_TYPE_POS,
    ST_FUNCTION_TYPE_DEPTH,
    ST_FUNCTION_TYPE_POS_EVEN,
    ST_FUNCTION_TYPE_VAR,
    ST_FUNCTION_TYPE_REV_POS,
    ST_FUNCTION_TYPE_MAX_DEPTH
} pptx_st_function_type_token_enum;

pptx_st_function_type_token_enum pptx_get_st_function_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_FUNCTION_TYPE_H__ */

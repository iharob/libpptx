#ifndef __PPTX_ST_FUNCTION_OPERATOR_H__
#define __PPTX_ST_FUNCTION_OPERATOR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_function_operator_token_enum {
    ST_FUNCTION_OPERATOR_GT,
    ST_FUNCTION_OPERATOR_GTE,
    ST_FUNCTION_OPERATOR_NIL,
    ST_FUNCTION_OPERATOR_EQU,
    ST_FUNCTION_OPERATOR_LT,
    ST_FUNCTION_OPERATOR_LTE,
    ST_FUNCTION_OPERATOR_NEQ
} pptx_st_function_operator_token_enum;

pptx_st_function_operator_token_enum pptx_get_st_function_operator(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_FUNCTION_OPERATOR_H__ */

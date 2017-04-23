#ifndef __PPTX_ST_BOOL_OPERATOR_H__
#define __PPTX_ST_BOOL_OPERATOR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_bool_operator_token_enum {
    ST_BOOL_OPERATOR_NIL,
    ST_BOOL_OPERATOR_NONE,
    ST_BOOL_OPERATOR_EQU,
    ST_BOOL_OPERATOR_GTE,
    ST_BOOL_OPERATOR_LTE
} pptx_st_bool_operator_token_enum;

pptx_st_bool_operator_token_enum pptx_get_st_bool_operator(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BOOL_OPERATOR_H__ */

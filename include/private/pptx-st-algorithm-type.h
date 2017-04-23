#ifndef __PPTX_ST_ALGORITHM_TYPE_H__
#define __PPTX_ST_ALGORITHM_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_algorithm_type_token_enum {
    ST_ALGORITHM_TYPE_HIER_ROOT,
    ST_ALGORITHM_TYPE_SP,
    ST_ALGORITHM_TYPE_NIL,
    ST_ALGORITHM_TYPE_TX,
    ST_ALGORITHM_TYPE_COMPOSITE,
    ST_ALGORITHM_TYPE_LIN,
    ST_ALGORITHM_TYPE_HIER_CHILD,
    ST_ALGORITHM_TYPE_SNAKE,
    ST_ALGORITHM_TYPE_CONN,
    ST_ALGORITHM_TYPE_PYRA,
    ST_ALGORITHM_TYPE_CYCLE
} pptx_st_algorithm_type_token_enum;

pptx_st_algorithm_type_token_enum pptx_get_st_algorithm_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ALGORITHM_TYPE_H__ */

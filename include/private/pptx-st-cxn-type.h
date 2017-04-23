#ifndef __PPTX_ST_CXN_TYPE_H__
#define __PPTX_ST_CXN_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_cxn_type_token_enum {
    ST_CXN_TYPE_UNKNOWN_RELATIONSHIP,
    ST_CXN_TYPE_PRES_OF,
    ST_CXN_TYPE_PRES_PAR_OF,
    ST_CXN_TYPE_NIL,
    ST_CXN_TYPE_PAR_OF
} pptx_st_cxn_type_token_enum;

pptx_st_cxn_type_token_enum pptx_get_st_cxn_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CXN_TYPE_H__ */

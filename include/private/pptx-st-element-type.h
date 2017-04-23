#ifndef __PPTX_ST_ELEMENT_TYPE_H__
#define __PPTX_ST_ELEMENT_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_element_type_token_enum {
    ST_ELEMENT_TYPE_NODE,
    ST_ELEMENT_TYPE_ALL,
    ST_ELEMENT_TYPE_NIL,
    ST_ELEMENT_TYPE_DOC,
    ST_ELEMENT_TYPE_SIB_TRANS,
    ST_ELEMENT_TYPE_NON_NORM,
    ST_ELEMENT_TYPE_PRES,
    ST_ELEMENT_TYPE_NON_ASST,
    ST_ELEMENT_TYPE_ASST,
    ST_ELEMENT_TYPE_PAR_TRANS,
    ST_ELEMENT_TYPE_NORM
} pptx_st_element_type_token_enum;

pptx_st_element_type_token_enum pptx_get_st_element_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ELEMENT_TYPE_H__ */

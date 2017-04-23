#ifndef __PPTX_ST_STARTING_ELEMENT_H__
#define __PPTX_ST_STARTING_ELEMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_starting_element_token_enum {
    ST_STARTING_ELEMENT_NODE,
    ST_STARTING_ELEMENT_TRANS,
    ST_STARTING_ELEMENT_NIL
} pptx_st_starting_element_token_enum;

pptx_st_starting_element_token_enum pptx_get_st_starting_element(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_STARTING_ELEMENT_H__ */

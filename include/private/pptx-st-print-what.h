#ifndef __PPTX_ST_PRINT_WHAT_H__
#define __PPTX_ST_PRINT_WHAT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_print_what_token_enum {
    ST_PRINT_WHAT_HANDOUTS1,
    ST_PRINT_WHAT_HANDOUTS3,
    ST_PRINT_WHAT_HANDOUTS2,
    ST_PRINT_WHAT_HANDOUTS4,
    ST_PRINT_WHAT_NIL,
    ST_PRINT_WHAT_HANDOUTS6,
    ST_PRINT_WHAT_HANDOUTS9,
    ST_PRINT_WHAT_NOTES,
    ST_PRINT_WHAT_SLIDES,
    ST_PRINT_WHAT_OUTLINE
} pptx_st_print_what_token_enum;

pptx_st_print_what_token_enum pptx_get_st_print_what(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PRINT_WHAT_H__ */

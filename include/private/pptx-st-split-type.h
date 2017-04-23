#ifndef __PPTX_ST_SPLIT_TYPE_H__
#define __PPTX_ST_SPLIT_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_split_type_text_enum {
    ST_SPLIT_TYPE_CUST,
    ST_SPLIT_TYPE_NIL,
    ST_SPLIT_TYPE_AUTO,
    ST_SPLIT_TYPE_PERCENT,
    ST_SPLIT_TYPE_POS,
    ST_SPLIT_TYPE_VAL
} pptx_st_split_type_text_enum;

pptx_st_split_type_text_enum pptx_get_st_split_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SPLIT_TYPE_H__ */

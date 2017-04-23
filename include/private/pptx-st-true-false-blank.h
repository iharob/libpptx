#ifndef __PPTX_ST_TRUE_FALSE_BLANK_H__
#define __PPTX_ST_TRUE_FALSE_BLANK_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_true_false_blank_text_enum {
    ST_TRUE_FALSE_BLANK_,
    ST_TRUE_FALSE_BLANK_FALSE,
    ST_TRUE_FALSE_BLANK_NIL,
    ST_TRUE_FALSE_BLANK_F,
    ST_TRUE_FALSE_BLANK_T,
    ST_TRUE_FALSE_BLANK_TRUE
} pptx_st_true_false_blank_text_enum;

pptx_st_true_false_blank_text_enum pptx_get_st_true_false_blank(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TRUE_FALSE_BLANK_H__ */

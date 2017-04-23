#ifndef __PPTX_ST_TRUE_FALSE_H__
#define __PPTX_ST_TRUE_FALSE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_true_false_text_enum {
    ST_TRUE_FALSE_FALSE,
    ST_TRUE_FALSE_TRUE,
    ST_TRUE_FALSE_T,
    ST_TRUE_FALSE_NIL,
    ST_TRUE_FALSE_F
} pptx_st_true_false_text_enum;

pptx_st_true_false_text_enum pptx_get_st_true_false(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TRUE_FALSE_H__ */

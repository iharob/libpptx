#ifndef __PPTX_ST_ALG_CLASS_H__
#define __PPTX_ST_ALG_CLASS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_alg_class_text_enum {
    ST_ALG_CLASS_HASH,
    ST_ALG_CLASS_NIL,
    ST_ALG_CLASS_CUSTOM
} pptx_st_alg_class_text_enum;

pptx_st_alg_class_text_enum pptx_get_st_alg_class(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ALG_CLASS_H__ */

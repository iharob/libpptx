#ifndef __PPTX_ST_CROSSES_H__
#define __PPTX_ST_CROSSES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_crosses_text_enum {
    ST_CROSSES_MAX,
    ST_CROSSES_AUTO_ZERO,
    ST_CROSSES_NIL,
    ST_CROSSES_MIN
} pptx_st_crosses_text_enum;

pptx_st_crosses_text_enum pptx_get_st_crosses(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CROSSES_H__ */

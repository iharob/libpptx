#ifndef __PPTX_ST_FALLBACK_DIMENSION_H__
#define __PPTX_ST_FALLBACK_DIMENSION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_fallback_dimension_token_enum {
    ST_FALLBACK_DIMENSION__2D,
    ST_FALLBACK_DIMENSION_1_D,
    ST_FALLBACK_DIMENSION_NIL
} pptx_st_fallback_dimension_token_enum;

pptx_st_fallback_dimension_token_enum pptx_get_st_fallback_dimension(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_FALLBACK_DIMENSION_H__ */

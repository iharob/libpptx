#ifndef __PPTX_ST_TLTIME_INDEFINITE_H__
#define __PPTX_ST_TLTIME_INDEFINITE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltime_indefinite_token_enum {
    ST_TLTIME_INDEFINITE_INDEFINITE,
    ST_TLTIME_INDEFINITE_NIL
} pptx_st_tltime_indefinite_token_enum;

pptx_st_tltime_indefinite_token_enum pptx_get_st_tltime_indefinite(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLTIME_INDEFINITE_H__ */

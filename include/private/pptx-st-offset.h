#ifndef __PPTX_ST_OFFSET_H__
#define __PPTX_ST_OFFSET_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_offset_token_enum {
    ST_OFFSET_OFF,
    ST_OFFSET_NIL,
    ST_OFFSET_CTR
} pptx_st_offset_token_enum;

pptx_st_offset_token_enum pptx_get_st_offset(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_OFFSET_H__ */

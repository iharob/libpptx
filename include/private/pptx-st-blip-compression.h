#ifndef __PPTX_ST_BLIP_COMPRESSION_H__
#define __PPTX_ST_BLIP_COMPRESSION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_blip_compression_token_enum {
    ST_BLIP_COMPRESSION_NONE,
    ST_BLIP_COMPRESSION_NIL,
    ST_BLIP_COMPRESSION_HQPRINT,
    ST_BLIP_COMPRESSION_SCREEN,
    ST_BLIP_COMPRESSION_PRINT,
    ST_BLIP_COMPRESSION_EMAIL
} pptx_st_blip_compression_token_enum;

pptx_st_blip_compression_token_enum pptx_get_st_blip_compression(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BLIP_COMPRESSION_H__ */

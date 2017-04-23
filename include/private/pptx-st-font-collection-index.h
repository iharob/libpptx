#ifndef __PPTX_ST_FONT_COLLECTION_INDEX_H__
#define __PPTX_ST_FONT_COLLECTION_INDEX_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_font_collection_index_token_enum {
    ST_FONT_COLLECTION_INDEX_NIL,
    ST_FONT_COLLECTION_INDEX_MAJOR,
    ST_FONT_COLLECTION_INDEX_NONE,
    ST_FONT_COLLECTION_INDEX_MINOR
} pptx_st_font_collection_index_token_enum;

pptx_st_font_collection_index_token_enum pptx_get_st_font_collection_index(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_FONT_COLLECTION_INDEX_H__ */

#ifndef __PPTX_ST_SLIDE_SIZE_TYPE_H__
#define __PPTX_ST_SLIDE_SIZE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_slide_size_type_token_enum {
    ST_SLIDE_SIZE_TYPE_B4_ISO,
    ST_SLIDE_SIZE_TYPE_B4_JIS,
    ST_SLIDE_SIZE_TYPE_SCREEN4X3,
    ST_SLIDE_SIZE_TYPE_B5_ISO,
    ST_SLIDE_SIZE_TYPE_NIL,
    ST_SLIDE_SIZE_TYPE_B5_JIS,
    ST_SLIDE_SIZE_TYPE_LEDGER,
    ST_SLIDE_SIZE_TYPE_CUSTOM,
    ST_SLIDE_SIZE_TYPE_35MM,
    ST_SLIDE_SIZE_TYPE_SCREEN16X10,
    ST_SLIDE_SIZE_TYPE_OVERHEAD,
    ST_SLIDE_SIZE_TYPE_A4,
    ST_SLIDE_SIZE_TYPE_LETTER,
    ST_SLIDE_SIZE_TYPE_HAGAKI_CARD,
    ST_SLIDE_SIZE_TYPE_SCREEN16X9,
    ST_SLIDE_SIZE_TYPE_BANNER,
    ST_SLIDE_SIZE_TYPE_A3
} pptx_st_slide_size_type_token_enum;

pptx_st_slide_size_type_token_enum pptx_get_st_slide_size_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SLIDE_SIZE_TYPE_H__ */

#ifndef __PPTX_ST_TEXT_ANCHOR_HORIZONTAL_H__
#define __PPTX_ST_TEXT_ANCHOR_HORIZONTAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_text_anchor_horizontal_token_enum {
    ST_TEXT_ANCHOR_HORIZONTAL_NONE,
    ST_TEXT_ANCHOR_HORIZONTAL_NIL,
    ST_TEXT_ANCHOR_HORIZONTAL_CTR
} pptx_st_text_anchor_horizontal_token_enum;

pptx_st_text_anchor_horizontal_token_enum pptx_get_st_text_anchor_horizontal(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TEXT_ANCHOR_HORIZONTAL_H__ */

#ifndef __PPTX_ST_RECT_ALIGNMENT_H__
#define __PPTX_ST_RECT_ALIGNMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_rect_alignment_token_enum {
    ST_RECT_ALIGNMENT_B,
    ST_RECT_ALIGNMENT_NIL,
    ST_RECT_ALIGNMENT_CTR,
    ST_RECT_ALIGNMENT_BL,
    ST_RECT_ALIGNMENT_TR,
    ST_RECT_ALIGNMENT_L,
    ST_RECT_ALIGNMENT_TL,
    ST_RECT_ALIGNMENT_R,
    ST_RECT_ALIGNMENT_T,
    ST_RECT_ALIGNMENT_BR
} pptx_st_rect_alignment_token_enum;

pptx_st_rect_alignment_token_enum pptx_get_st_rect_alignment(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_RECT_ALIGNMENT_H__ */

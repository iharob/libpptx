#ifndef __PPTX_ST_PEN_ALIGNMENT_H__
#define __PPTX_ST_PEN_ALIGNMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_pen_alignment_token_enum {
    ST_PEN_ALIGNMENT_NIL,
    ST_PEN_ALIGNMENT_CTR,
    ST_PEN_ALIGNMENT_IN
} pptx_st_pen_alignment_token_enum;

pptx_st_pen_alignment_token_enum pptx_get_st_pen_alignment(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PEN_ALIGNMENT_H__ */

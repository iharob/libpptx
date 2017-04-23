#ifndef __PPTX_ST_DIAGRAM_HORIZONTAL_ALIGNMENT_H__
#define __PPTX_ST_DIAGRAM_HORIZONTAL_ALIGNMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_diagram_horizontal_alignment_token_enum {
    ST_DIAGRAM_HORIZONTAL_ALIGNMENT_NIL,
    ST_DIAGRAM_HORIZONTAL_ALIGNMENT_NONE,
    ST_DIAGRAM_HORIZONTAL_ALIGNMENT_R,
    ST_DIAGRAM_HORIZONTAL_ALIGNMENT_L,
    ST_DIAGRAM_HORIZONTAL_ALIGNMENT_CTR
} pptx_st_diagram_horizontal_alignment_token_enum;

pptx_st_diagram_horizontal_alignment_token_enum pptx_get_st_diagram_horizontal_alignment(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_DIAGRAM_HORIZONTAL_ALIGNMENT_H__ */

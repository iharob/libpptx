#ifndef __PPTX_ST_SECONDARY_CHILD_ALIGNMENT_H__
#define __PPTX_ST_SECONDARY_CHILD_ALIGNMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_secondary_child_alignment_token_enum {
    ST_SECONDARY_CHILD_ALIGNMENT_NONE,
    ST_SECONDARY_CHILD_ALIGNMENT_B,
    ST_SECONDARY_CHILD_ALIGNMENT_NIL,
    ST_SECONDARY_CHILD_ALIGNMENT_L,
    ST_SECONDARY_CHILD_ALIGNMENT_R,
    ST_SECONDARY_CHILD_ALIGNMENT_T
} pptx_st_secondary_child_alignment_token_enum;

pptx_st_secondary_child_alignment_token_enum pptx_get_st_secondary_child_alignment(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SECONDARY_CHILD_ALIGNMENT_H__ */

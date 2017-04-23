#ifndef __PPTX_ST_HIER_BRANCH_STYLE_H__
#define __PPTX_ST_HIER_BRANCH_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_hier_branch_style_token_enum {
    ST_HIER_BRANCH_STYLE_STD,
    ST_HIER_BRANCH_STYLE_NIL,
    ST_HIER_BRANCH_STYLE_HANG,
    ST_HIER_BRANCH_STYLE_L,
    ST_HIER_BRANCH_STYLE_INIT,
    ST_HIER_BRANCH_STYLE_R
} pptx_st_hier_branch_style_token_enum;

pptx_st_hier_branch_style_token_enum pptx_get_st_hier_branch_style(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_HIER_BRANCH_STYLE_H__ */

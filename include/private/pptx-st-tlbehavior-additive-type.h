#ifndef __PPTX_ST_TLBEHAVIOR_ADDITIVE_TYPE_H__
#define __PPTX_ST_TLBEHAVIOR_ADDITIVE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlbehavior_additive_type_token_enum {
    ST_TLBEHAVIOR_ADDITIVE_TYPE_NONE,
    ST_TLBEHAVIOR_ADDITIVE_TYPE_NIL,
    ST_TLBEHAVIOR_ADDITIVE_TYPE_REPL,
    ST_TLBEHAVIOR_ADDITIVE_TYPE_SUM,
    ST_TLBEHAVIOR_ADDITIVE_TYPE_BASE,
    ST_TLBEHAVIOR_ADDITIVE_TYPE_MULT
} pptx_st_tlbehavior_additive_type_token_enum;

pptx_st_tlbehavior_additive_type_token_enum pptx_get_st_tlbehavior_additive_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLBEHAVIOR_ADDITIVE_TYPE_H__ */

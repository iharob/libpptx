#ifndef __PPTX_ST_CONSTRAINT_RELATIONSHIP_H__
#define __PPTX_ST_CONSTRAINT_RELATIONSHIP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_constraint_relationship_token_enum {
    ST_CONSTRAINT_RELATIONSHIP_SELF,
    ST_CONSTRAINT_RELATIONSHIP_CH,
    ST_CONSTRAINT_RELATIONSHIP_DES,
    ST_CONSTRAINT_RELATIONSHIP_NIL
} pptx_st_constraint_relationship_token_enum;

pptx_st_constraint_relationship_token_enum pptx_get_st_constraint_relationship(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CONSTRAINT_RELATIONSHIP_H__ */

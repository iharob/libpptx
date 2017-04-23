#ifndef __PPTX_ST_HIERARCHY_ALIGNMENT_H__
#define __PPTX_ST_HIERARCHY_ALIGNMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_hierarchy_alignment_token_enum {
    ST_HIERARCHY_ALIGNMENT_R_T,
    ST_HIERARCHY_ALIGNMENT_R_CTR_CH,
    ST_HIERARCHY_ALIGNMENT_R_CTR_DES,
    ST_HIERARCHY_ALIGNMENT_L_B,
    ST_HIERARCHY_ALIGNMENT_R_B,
    ST_HIERARCHY_ALIGNMENT_T_CTR_CH,
    ST_HIERARCHY_ALIGNMENT_B_L,
    ST_HIERARCHY_ALIGNMENT_T_R,
    ST_HIERARCHY_ALIGNMENT_B_CTR_DES,
    ST_HIERARCHY_ALIGNMENT_B_CTR_CH,
    ST_HIERARCHY_ALIGNMENT_L_T,
    ST_HIERARCHY_ALIGNMENT_T_L,
    ST_HIERARCHY_ALIGNMENT_L_CTR_DES,
    ST_HIERARCHY_ALIGNMENT_B_R,
    ST_HIERARCHY_ALIGNMENT_NIL,
    ST_HIERARCHY_ALIGNMENT_T_CTR_DES,
    ST_HIERARCHY_ALIGNMENT_L_CTR_CH
} pptx_st_hierarchy_alignment_token_enum;

pptx_st_hierarchy_alignment_token_enum pptx_get_st_hierarchy_alignment(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_HIERARCHY_ALIGNMENT_H__ */

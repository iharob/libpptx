#ifndef __PPTX_ST_TLDIAGRAM_BUILD_TYPE_H__
#define __PPTX_ST_TLDIAGRAM_BUILD_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tldiagram_build_type_token_enum {
    ST_TLDIAGRAM_BUILD_TYPE_OUT_BY_RING,
    ST_TLDIAGRAM_BUILD_TYPE_CUST,
    ST_TLDIAGRAM_BUILD_TYPE_NIL,
    ST_TLDIAGRAM_BUILD_TYPE_IN_BY_RING,
    ST_TLDIAGRAM_BUILD_TYPE_DEPTH_BY_BRANCH,
    ST_TLDIAGRAM_BUILD_TYPE_CCW,
    ST_TLDIAGRAM_BUILD_TYPE_DEPTH_BY_NODE,
    ST_TLDIAGRAM_BUILD_TYPE_UP,
    ST_TLDIAGRAM_BUILD_TYPE_CW_OUT,
    ST_TLDIAGRAM_BUILD_TYPE_DOWN,
    ST_TLDIAGRAM_BUILD_TYPE_ALL_AT_ONCE,
    ST_TLDIAGRAM_BUILD_TYPE_CW_IN,
    ST_TLDIAGRAM_BUILD_TYPE_BREADTH_BY_NODE,
    ST_TLDIAGRAM_BUILD_TYPE_CW,
    ST_TLDIAGRAM_BUILD_TYPE_CCW_OUT,
    ST_TLDIAGRAM_BUILD_TYPE_BREADTH_BY_LVL,
    ST_TLDIAGRAM_BUILD_TYPE_WHOLE,
    ST_TLDIAGRAM_BUILD_TYPE_CCW_IN
} pptx_st_tldiagram_build_type_token_enum;

pptx_st_tldiagram_build_type_token_enum pptx_get_st_tldiagram_build_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLDIAGRAM_BUILD_TYPE_H__ */

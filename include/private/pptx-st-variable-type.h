#ifndef __PPTX_ST_VARIABLE_TYPE_H__
#define __PPTX_ST_VARIABLE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_variable_type_token_enum {
    ST_VARIABLE_TYPE_RESIZE_HANDLES,
    ST_VARIABLE_TYPE_NONE,
    ST_VARIABLE_TYPE_NIL,
    ST_VARIABLE_TYPE_ANIM_LVL,
    ST_VARIABLE_TYPE_HIER_BRANCH,
    ST_VARIABLE_TYPE_CH_PREF,
    ST_VARIABLE_TYPE_ANIM_ONE,
    ST_VARIABLE_TYPE_ORG_CHART,
    ST_VARIABLE_TYPE_BUL_ENABLED,
    ST_VARIABLE_TYPE_CH_MAX,
    ST_VARIABLE_TYPE_DIR
} pptx_st_variable_type_token_enum;

pptx_st_variable_type_token_enum pptx_get_st_variable_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_VARIABLE_TYPE_H__ */

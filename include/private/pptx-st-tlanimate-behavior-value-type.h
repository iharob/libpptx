#ifndef __PPTX_ST_TLANIMATE_BEHAVIOR_VALUE_TYPE_H__
#define __PPTX_ST_TLANIMATE_BEHAVIOR_VALUE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlanimate_behavior_value_type_token_enum {
    ST_TLANIMATE_BEHAVIOR_VALUE_TYPE_NIL,
    ST_TLANIMATE_BEHAVIOR_VALUE_TYPE_NUM,
    ST_TLANIMATE_BEHAVIOR_VALUE_TYPE_CLR,
    ST_TLANIMATE_BEHAVIOR_VALUE_TYPE_STR
} pptx_st_tlanimate_behavior_value_type_token_enum;

pptx_st_tlanimate_behavior_value_type_token_enum pptx_get_st_tlanimate_behavior_value_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLANIMATE_BEHAVIOR_VALUE_TYPE_H__ */

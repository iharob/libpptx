#ifndef __PPTX_ST_AXIS_TYPE_H__
#define __PPTX_ST_AXIS_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_axis_type_token_enum {
    ST_AXIS_TYPE_PAR,
    ST_AXIS_TYPE_CH,
    ST_AXIS_TYPE_DES_OR_SELF,
    ST_AXIS_TYPE_NIL,
    ST_AXIS_TYPE_PRECED_SIB,
    ST_AXIS_TYPE_SELF,
    ST_AXIS_TYPE_DES,
    ST_AXIS_TYPE_ANCST,
    ST_AXIS_TYPE_FOLLOW_SIB,
    ST_AXIS_TYPE_PRECED,
    ST_AXIS_TYPE_NONE,
    ST_AXIS_TYPE_FOLLOW,
    ST_AXIS_TYPE_ROOT,
    ST_AXIS_TYPE_ANCST_OR_SELF
} pptx_st_axis_type_token_enum;

pptx_st_axis_type_token_enum pptx_get_st_axis_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_AXIS_TYPE_H__ */

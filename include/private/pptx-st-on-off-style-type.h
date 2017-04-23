#ifndef __PPTX_ST_ON_OFF_STYLE_TYPE_H__
#define __PPTX_ST_ON_OFF_STYLE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_on_off_style_type_token_enum {
    ST_ON_OFF_STYLE_TYPE_ON,
    ST_ON_OFF_STYLE_TYPE_OFF,
    ST_ON_OFF_STYLE_TYPE_NIL,
    ST_ON_OFF_STYLE_TYPE_DEF
} pptx_st_on_off_style_type_token_enum;

pptx_st_on_off_style_type_token_enum pptx_get_st_on_off_style_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ON_OFF_STYLE_TYPE_H__ */

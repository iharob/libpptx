#ifndef __PPTX_ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_H__
#define __PPTX_ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_ole_object_follow_color_scheme_token_enum {
    ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_NONE,
    ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_FULL,
    ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_TEXT_AND_BACKGROUND,
    ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_NIL
} pptx_st_ole_object_follow_color_scheme_token_enum;

pptx_st_ole_object_follow_color_scheme_token_enum pptx_get_st_ole_object_follow_color_scheme(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_H__ */

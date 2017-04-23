#ifndef __PPTX_ST_CLR_APP_METHOD_H__
#define __PPTX_ST_CLR_APP_METHOD_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_clr_app_method_token_enum {
    ST_CLR_APP_METHOD_REPEAT,
    ST_CLR_APP_METHOD_SPAN,
    ST_CLR_APP_METHOD_NIL,
    ST_CLR_APP_METHOD_CYCLE
} pptx_st_clr_app_method_token_enum;

pptx_st_clr_app_method_token_enum pptx_get_st_clr_app_method(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CLR_APP_METHOD_H__ */

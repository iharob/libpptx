#ifndef __PPTX_ST_ERR_BAR_TYPE_H__
#define __PPTX_ST_ERR_BAR_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_err_bar_type_text_enum {
    ST_ERR_BAR_TYPE_BOTH,
    ST_ERR_BAR_TYPE_PLUS,
    ST_ERR_BAR_TYPE_MINUS,
    ST_ERR_BAR_TYPE_NIL
} pptx_st_err_bar_type_text_enum;

pptx_st_err_bar_type_text_enum pptx_get_st_err_bar_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ERR_BAR_TYPE_H__ */

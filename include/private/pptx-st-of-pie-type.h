#ifndef __PPTX_ST_OF_PIE_TYPE_H__
#define __PPTX_ST_OF_PIE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_of_pie_type_text_enum {
    ST_OF_PIE_TYPE_BAR,
    ST_OF_PIE_TYPE_PIE,
    ST_OF_PIE_TYPE_NIL
} pptx_st_of_pie_type_text_enum;

pptx_st_of_pie_type_text_enum pptx_get_st_of_pie_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_OF_PIE_TYPE_H__ */

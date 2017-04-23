#ifndef __PPTX_ST_CROSS_BETWEEN_H__
#define __PPTX_ST_CROSS_BETWEEN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_cross_between_text_enum {
    ST_CROSS_BETWEEN_MID_CAT,
    ST_CROSS_BETWEEN_NIL,
    ST_CROSS_BETWEEN_BETWEEN
} pptx_st_cross_between_text_enum;

pptx_st_cross_between_text_enum pptx_get_st_cross_between(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CROSS_BETWEEN_H__ */

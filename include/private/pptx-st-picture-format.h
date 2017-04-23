#ifndef __PPTX_ST_PICTURE_FORMAT_H__
#define __PPTX_ST_PICTURE_FORMAT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_picture_format_text_enum {
    ST_PICTURE_FORMAT_STRETCH,
    ST_PICTURE_FORMAT_STACK_SCALE,
    ST_PICTURE_FORMAT_STACK,
    ST_PICTURE_FORMAT_NIL
} pptx_st_picture_format_text_enum;

pptx_st_picture_format_text_enum pptx_get_st_picture_format(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PICTURE_FORMAT_H__ */

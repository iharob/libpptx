#ifndef __PPTX_ST_LAYOUT_MODE_H__
#define __PPTX_ST_LAYOUT_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_layout_mode_text_enum {
    ST_LAYOUT_MODE_EDGE,
    ST_LAYOUT_MODE_NIL,
    ST_LAYOUT_MODE_FACTOR
} pptx_st_layout_mode_text_enum;

pptx_st_layout_mode_text_enum pptx_get_st_layout_mode(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_LAYOUT_MODE_H__ */

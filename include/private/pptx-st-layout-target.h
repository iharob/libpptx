#ifndef __PPTX_ST_LAYOUT_TARGET_H__
#define __PPTX_ST_LAYOUT_TARGET_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_layout_target_text_enum {
    ST_LAYOUT_TARGET_OUTER,
    ST_LAYOUT_TARGET_INNER,
    ST_LAYOUT_TARGET_NIL
} pptx_st_layout_target_text_enum;

pptx_st_layout_target_text_enum pptx_get_st_layout_target(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_LAYOUT_TARGET_H__ */

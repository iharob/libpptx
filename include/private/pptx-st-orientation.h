#ifndef __PPTX_ST_ORIENTATION_H__
#define __PPTX_ST_ORIENTATION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_orientation_text_enum {
    ST_ORIENTATION_MAX_MIN,
    ST_ORIENTATION_MIN_MAX,
    ST_ORIENTATION_NIL
} pptx_st_orientation_text_enum;

pptx_st_orientation_text_enum pptx_get_st_orientation(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ORIENTATION_H__ */

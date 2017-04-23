#ifndef __PPTX_ST_SIZE_REPRESENTS_H__
#define __PPTX_ST_SIZE_REPRESENTS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_size_represents_text_enum {
    ST_SIZE_REPRESENTS_NIL,
    ST_SIZE_REPRESENTS_W,
    ST_SIZE_REPRESENTS_AREA
} pptx_st_size_represents_text_enum;

pptx_st_size_represents_text_enum pptx_get_st_size_represents(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SIZE_REPRESENTS_H__ */

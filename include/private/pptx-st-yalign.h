#ifndef __PPTX_ST_YALIGN_H__
#define __PPTX_ST_YALIGN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_yalign_text_enum {
    ST_YALIGN_CENTER,
    ST_YALIGN_NIL,
    ST_YALIGN_BOTTOM,
    ST_YALIGN_TOP,
    ST_YALIGN_OUTSIDE,
    ST_YALIGN_INLINE,
    ST_YALIGN_INSIDE
} pptx_st_yalign_text_enum;

pptx_st_yalign_text_enum pptx_get_st_yalign(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_YALIGN_H__ */

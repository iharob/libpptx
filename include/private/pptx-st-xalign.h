#ifndef __PPTX_ST_XALIGN_H__
#define __PPTX_ST_XALIGN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_xalign_text_enum {
    ST_XALIGN_RIGHT,
    ST_XALIGN_CENTER,
    ST_XALIGN_NIL,
    ST_XALIGN_INSIDE,
    ST_XALIGN_OUTSIDE,
    ST_XALIGN_LEFT
} pptx_st_xalign_text_enum;

pptx_st_xalign_text_enum pptx_get_st_xalign(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_XALIGN_H__ */

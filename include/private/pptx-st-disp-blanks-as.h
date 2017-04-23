#ifndef __PPTX_ST_DISP_BLANKS_AS_H__
#define __PPTX_ST_DISP_BLANKS_AS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_disp_blanks_as_text_enum {
    ST_DISP_BLANKS_AS_ZERO,
    ST_DISP_BLANKS_AS_SPAN,
    ST_DISP_BLANKS_AS_NIL,
    ST_DISP_BLANKS_AS_GAP
} pptx_st_disp_blanks_as_text_enum;

pptx_st_disp_blanks_as_text_enum pptx_get_st_disp_blanks_as(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_DISP_BLANKS_AS_H__ */

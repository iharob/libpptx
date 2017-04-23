#ifndef __PPTX_ST_VERTICAL_ALIGN_RUN_H__
#define __PPTX_ST_VERTICAL_ALIGN_RUN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_vertical_align_run_text_enum {
    ST_VERTICAL_ALIGN_RUN_SUBSCRIPT,
    ST_VERTICAL_ALIGN_RUN_BASELINE,
    ST_VERTICAL_ALIGN_RUN_NIL,
    ST_VERTICAL_ALIGN_RUN_SUPERSCRIPT
} pptx_st_vertical_align_run_text_enum;

pptx_st_vertical_align_run_text_enum pptx_get_st_vertical_align_run(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_VERTICAL_ALIGN_RUN_H__ */

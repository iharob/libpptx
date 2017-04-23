#ifndef __PPTX_ST_PAGE_SETUP_ORIENTATION_H__
#define __PPTX_ST_PAGE_SETUP_ORIENTATION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_page_setup_orientation_text_enum {
    ST_PAGE_SETUP_ORIENTATION_DEFAULT,
    ST_PAGE_SETUP_ORIENTATION_PORTRAIT,
    ST_PAGE_SETUP_ORIENTATION_NIL,
    ST_PAGE_SETUP_ORIENTATION_LANDSCAPE
} pptx_st_page_setup_orientation_text_enum;

pptx_st_page_setup_orientation_text_enum pptx_get_st_page_setup_orientation(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PAGE_SETUP_ORIENTATION_H__ */

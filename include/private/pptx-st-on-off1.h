#ifndef __PPTX_ST_ON_OFF1_H__
#define __PPTX_ST_ON_OFF1_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_on_off1_text_enum {
    ST_ON_OFF1_ON,
    ST_ON_OFF1_OFF,
    ST_ON_OFF1_NIL
} pptx_st_on_off1_text_enum;

pptx_st_on_off1_text_enum pptx_get_st_on_off1(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ON_OFF1_H__ */

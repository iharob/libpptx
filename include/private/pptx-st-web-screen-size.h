#ifndef __PPTX_ST_WEB_SCREEN_SIZE_H__
#define __PPTX_ST_WEB_SCREEN_SIZE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_web_screen_size_token_enum {
    ST_WEB_SCREEN_SIZE_1920X1200,
    ST_WEB_SCREEN_SIZE_NIL,
    ST_WEB_SCREEN_SIZE_720X512,
    ST_WEB_SCREEN_SIZE_800X600,
    ST_WEB_SCREEN_SIZE_1152X900,
    ST_WEB_SCREEN_SIZE_1800X1400,
    ST_WEB_SCREEN_SIZE_1600X1200,
    ST_WEB_SCREEN_SIZE_1024X768,
    ST_WEB_SCREEN_SIZE_640X480,
    ST_WEB_SCREEN_SIZE_1152X882,
    ST_WEB_SCREEN_SIZE_1280X1024,
    ST_WEB_SCREEN_SIZE_544X376
} pptx_st_web_screen_size_token_enum;

pptx_st_web_screen_size_token_enum pptx_get_st_web_screen_size(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_WEB_SCREEN_SIZE_H__ */

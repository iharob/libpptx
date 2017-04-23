#ifndef __PPTX_ST_AUTO_TEXT_ROTATION_H__
#define __PPTX_ST_AUTO_TEXT_ROTATION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_auto_text_rotation_token_enum {
    ST_AUTO_TEXT_ROTATION_NONE,
    ST_AUTO_TEXT_ROTATION_UPR,
    ST_AUTO_TEXT_ROTATION_NIL,
    ST_AUTO_TEXT_ROTATION_GRAV
} pptx_st_auto_text_rotation_token_enum;

pptx_st_auto_text_rotation_token_enum pptx_get_st_auto_text_rotation(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_AUTO_TEXT_ROTATION_H__ */

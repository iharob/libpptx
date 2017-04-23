#ifndef __PPTX_ST_ROTATION_PATH_H__
#define __PPTX_ST_ROTATION_PATH_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_rotation_path_token_enum {
    ST_ROTATION_PATH_NONE,
    ST_ROTATION_PATH_ALONG_PATH,
    ST_ROTATION_PATH_NIL
} pptx_st_rotation_path_token_enum;

pptx_st_rotation_path_token_enum pptx_get_st_rotation_path(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ROTATION_PATH_H__ */

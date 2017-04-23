#ifndef __PPTX_ST_HUE_DIR_H__
#define __PPTX_ST_HUE_DIR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_hue_dir_token_enum {
    ST_HUE_DIR_CCW,
    ST_HUE_DIR_CW,
    ST_HUE_DIR_NIL
} pptx_st_hue_dir_token_enum;

pptx_st_hue_dir_token_enum pptx_get_st_hue_dir(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_HUE_DIR_H__ */

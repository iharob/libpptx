#ifndef __PPTX_ST_ERR_DIR_H__
#define __PPTX_ST_ERR_DIR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_err_dir_text_enum {
    ST_ERR_DIR_Y,
    ST_ERR_DIR_X,
    ST_ERR_DIR_NIL
} pptx_st_err_dir_text_enum;

pptx_st_err_dir_text_enum pptx_get_st_err_dir(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ERR_DIR_H__ */

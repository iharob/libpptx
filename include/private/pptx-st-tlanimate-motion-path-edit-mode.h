#ifndef __PPTX_ST_TLANIMATE_MOTION_PATH_EDIT_MODE_H__
#define __PPTX_ST_TLANIMATE_MOTION_PATH_EDIT_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tlanimate_motion_path_edit_mode_token_enum {
    ST_TLANIMATE_MOTION_PATH_EDIT_MODE_RELATIVE,
    ST_TLANIMATE_MOTION_PATH_EDIT_MODE_FIXED,
    ST_TLANIMATE_MOTION_PATH_EDIT_MODE_NIL
} pptx_st_tlanimate_motion_path_edit_mode_token_enum;

pptx_st_tlanimate_motion_path_edit_mode_token_enum pptx_get_st_tlanimate_motion_path_edit_mode(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLANIMATE_MOTION_PATH_EDIT_MODE_H__ */

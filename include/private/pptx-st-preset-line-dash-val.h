#ifndef __PPTX_ST_PRESET_LINE_DASH_VAL_H__
#define __PPTX_ST_PRESET_LINE_DASH_VAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_preset_line_dash_val_token_enum {
    ST_PRESET_LINE_DASH_VAL_NIL,
    ST_PRESET_LINE_DASH_VAL_DASH_DOT,
    ST_PRESET_LINE_DASH_VAL_SOLID,
    ST_PRESET_LINE_DASH_VAL_SYS_DASH_DOT_DOT,
    ST_PRESET_LINE_DASH_VAL_LG_DASH,
    ST_PRESET_LINE_DASH_VAL_SYS_DASH_DOT,
    ST_PRESET_LINE_DASH_VAL_LG_DASH_DOT_DOT,
    ST_PRESET_LINE_DASH_VAL_DASH,
    ST_PRESET_LINE_DASH_VAL_SYS_DOT,
    ST_PRESET_LINE_DASH_VAL_SYS_DASH,
    ST_PRESET_LINE_DASH_VAL_LG_DASH_DOT,
    ST_PRESET_LINE_DASH_VAL_DOT
} pptx_st_preset_line_dash_val_token_enum;

pptx_st_preset_line_dash_val_token_enum pptx_get_st_preset_line_dash_val(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PRESET_LINE_DASH_VAL_H__ */

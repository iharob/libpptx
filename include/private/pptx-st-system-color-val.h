#ifndef __PPTX_ST_SYSTEM_COLOR_VAL_H__
#define __PPTX_ST_SYSTEM_COLOR_VAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_system_color_val_token_enum {
    ST_SYSTEM_COLOR_VAL_ACTIVE_CAPTION,
    ST_SYSTEM_COLOR_VAL_3D_DK_SHADOW,
    ST_SYSTEM_COLOR_VAL_APP_WORKSPACE,
    ST_SYSTEM_COLOR_VAL_WINDOW_TEXT,
    ST_SYSTEM_COLOR_VAL_GRADIENT_ACTIVE_CAPTION,
    ST_SYSTEM_COLOR_VAL_HIGHLIGHT_TEXT,
    ST_SYSTEM_COLOR_VAL_INACTIVE_CAPTION,
    ST_SYSTEM_COLOR_VAL_3D_LIGHT,
    ST_SYSTEM_COLOR_VAL_INFO_BK,
    ST_SYSTEM_COLOR_VAL_MENU,
    ST_SYSTEM_COLOR_VAL_WINDOW,
    ST_SYSTEM_COLOR_VAL_GRAY_TEXT,
    ST_SYSTEM_COLOR_VAL_BTN_TEXT,
    ST_SYSTEM_COLOR_VAL_INACTIVE_CAPTION_TEXT,
    ST_SYSTEM_COLOR_VAL_NIL,
    ST_SYSTEM_COLOR_VAL_CAPTION_TEXT,
    ST_SYSTEM_COLOR_VAL_BTN_HIGHLIGHT,
    ST_SYSTEM_COLOR_VAL_BACKGROUND,
    ST_SYSTEM_COLOR_VAL_INACTIVE_BORDER,
    ST_SYSTEM_COLOR_VAL_WINDOW_FRAME,
    ST_SYSTEM_COLOR_VAL_BTN_FACE,
    ST_SYSTEM_COLOR_VAL_ACTIVE_BORDER,
    ST_SYSTEM_COLOR_VAL_INFO_TEXT,
    ST_SYSTEM_COLOR_VAL_SCROLL_BAR,
    ST_SYSTEM_COLOR_VAL_HOT_LIGHT,
    ST_SYSTEM_COLOR_VAL_MENU_TEXT,
    ST_SYSTEM_COLOR_VAL_HIGHLIGHT,
    ST_SYSTEM_COLOR_VAL_MENU_HIGHLIGHT,
    ST_SYSTEM_COLOR_VAL_GRADIENT_INACTIVE_CAPTION,
    ST_SYSTEM_COLOR_VAL_BTN_SHADOW,
    ST_SYSTEM_COLOR_VAL_MENU_BAR
} pptx_st_system_color_val_token_enum;

pptx_st_system_color_val_token_enum pptx_get_st_system_color_val(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_SYSTEM_COLOR_VAL_H__ */

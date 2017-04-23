#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-system-color-val.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_system_color_val_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_system_color_val_token_enum
pptx_get_st_system_color_val(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[31] = {
      {"3dDkShadow", ST_SYSTEM_COLOR_VAL_3D_DK_SHADOW},
      {"3dLight", ST_SYSTEM_COLOR_VAL_3D_LIGHT},
      {"activeBorder", ST_SYSTEM_COLOR_VAL_ACTIVE_BORDER},
      {"activeCaption", ST_SYSTEM_COLOR_VAL_ACTIVE_CAPTION},
      {"appWorkspace", ST_SYSTEM_COLOR_VAL_APP_WORKSPACE},
      {"background", ST_SYSTEM_COLOR_VAL_BACKGROUND},
      {"btnFace", ST_SYSTEM_COLOR_VAL_BTN_FACE},
      {"btnHighlight", ST_SYSTEM_COLOR_VAL_BTN_HIGHLIGHT},
      {"btnShadow", ST_SYSTEM_COLOR_VAL_BTN_SHADOW},
      {"btnText", ST_SYSTEM_COLOR_VAL_BTN_TEXT},
      {"captionText", ST_SYSTEM_COLOR_VAL_CAPTION_TEXT},
      {"gradientActiveCaption", ST_SYSTEM_COLOR_VAL_GRADIENT_ACTIVE_CAPTION},
      {"gradientInactiveCaption", ST_SYSTEM_COLOR_VAL_GRADIENT_INACTIVE_CAPTION},
      {"grayText", ST_SYSTEM_COLOR_VAL_GRAY_TEXT},
      {"highlight", ST_SYSTEM_COLOR_VAL_HIGHLIGHT},
      {"highlightText", ST_SYSTEM_COLOR_VAL_HIGHLIGHT_TEXT},
      {"hotLight", ST_SYSTEM_COLOR_VAL_HOT_LIGHT},
      {"inactiveBorder", ST_SYSTEM_COLOR_VAL_INACTIVE_BORDER},
      {"inactiveCaption", ST_SYSTEM_COLOR_VAL_INACTIVE_CAPTION},
      {"inactiveCaptionText", ST_SYSTEM_COLOR_VAL_INACTIVE_CAPTION_TEXT},
      {"infoBk", ST_SYSTEM_COLOR_VAL_INFO_BK},
      {"infoText", ST_SYSTEM_COLOR_VAL_INFO_TEXT},
      {"menu", ST_SYSTEM_COLOR_VAL_MENU},
      {"menuBar", ST_SYSTEM_COLOR_VAL_MENU_BAR},
      {"menuHighlight", ST_SYSTEM_COLOR_VAL_MENU_HIGHLIGHT},
      {"menuText", ST_SYSTEM_COLOR_VAL_MENU_TEXT},
      {"nil", ST_SYSTEM_COLOR_VAL_NIL},
      {"scrollBar", ST_SYSTEM_COLOR_VAL_SCROLL_BAR},
      {"window", ST_SYSTEM_COLOR_VAL_WINDOW},
      {"windowFrame", ST_SYSTEM_COLOR_VAL_WINDOW_FRAME},
      {"windowText", ST_SYSTEM_COLOR_VAL_WINDOW_TEXT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_SYSTEM_COLOR_VAL_NIL;
    // Perform binary search
    found = bsearch(&key, base, 31, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_SYSTEM_COLOR_VAL_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

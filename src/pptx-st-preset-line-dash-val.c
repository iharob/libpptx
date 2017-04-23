#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-preset-line-dash-val.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_preset_line_dash_val_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_preset_line_dash_val_token_enum
pptx_get_st_preset_line_dash_val(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[12] = {
      {"dash", ST_PRESET_LINE_DASH_VAL_DASH},
      {"dashDot", ST_PRESET_LINE_DASH_VAL_DASH_DOT},
      {"dot", ST_PRESET_LINE_DASH_VAL_DOT},
      {"lgDash", ST_PRESET_LINE_DASH_VAL_LG_DASH},
      {"lgDashDot", ST_PRESET_LINE_DASH_VAL_LG_DASH_DOT},
      {"lgDashDotDot", ST_PRESET_LINE_DASH_VAL_LG_DASH_DOT_DOT},
      {"nil", ST_PRESET_LINE_DASH_VAL_NIL},
      {"solid", ST_PRESET_LINE_DASH_VAL_SOLID},
      {"sysDash", ST_PRESET_LINE_DASH_VAL_SYS_DASH},
      {"sysDashDot", ST_PRESET_LINE_DASH_VAL_SYS_DASH_DOT},
      {"sysDashDotDot", ST_PRESET_LINE_DASH_VAL_SYS_DASH_DOT_DOT},
      {"sysDot", ST_PRESET_LINE_DASH_VAL_SYS_DOT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PRESET_LINE_DASH_VAL_NIL;
    // Perform binary search
    found = bsearch(&key, base, 12, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PRESET_LINE_DASH_VAL_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

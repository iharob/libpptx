#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-text-underline-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_text_underline_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_text_underline_type_token_enum
pptx_get_st_text_underline_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[19] = {
      {"dash", ST_TEXT_UNDERLINE_TYPE_DASH},
      {"dashHeavy", ST_TEXT_UNDERLINE_TYPE_DASH_HEAVY},
      {"dashLong", ST_TEXT_UNDERLINE_TYPE_DASH_LONG},
      {"dashLongHeavy", ST_TEXT_UNDERLINE_TYPE_DASH_LONG_HEAVY},
      {"dbl", ST_TEXT_UNDERLINE_TYPE_DBL},
      {"dotDash", ST_TEXT_UNDERLINE_TYPE_DOT_DASH},
      {"dotDashHeavy", ST_TEXT_UNDERLINE_TYPE_DOT_DASH_HEAVY},
      {"dotDotDash", ST_TEXT_UNDERLINE_TYPE_DOT_DOT_DASH},
      {"dotDotDashHeavy", ST_TEXT_UNDERLINE_TYPE_DOT_DOT_DASH_HEAVY},
      {"dotted", ST_TEXT_UNDERLINE_TYPE_DOTTED},
      {"dottedHeavy", ST_TEXT_UNDERLINE_TYPE_DOTTED_HEAVY},
      {"heavy", ST_TEXT_UNDERLINE_TYPE_HEAVY},
      {"nil", ST_TEXT_UNDERLINE_TYPE_NIL},
      {"none", ST_TEXT_UNDERLINE_TYPE_NONE},
      {"sng", ST_TEXT_UNDERLINE_TYPE_SNG},
      {"wavy", ST_TEXT_UNDERLINE_TYPE_WAVY},
      {"wavyDbl", ST_TEXT_UNDERLINE_TYPE_WAVY_DBL},
      {"wavyHeavy", ST_TEXT_UNDERLINE_TYPE_WAVY_HEAVY},
      {"words", ST_TEXT_UNDERLINE_TYPE_WORDS}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TEXT_UNDERLINE_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 19, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TEXT_UNDERLINE_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

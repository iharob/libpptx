#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-web-color-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_web_color_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_web_color_type_token_enum
pptx_get_st_web_color_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"blackTextOnWhite", ST_WEB_COLOR_TYPE_BLACK_TEXT_ON_WHITE},
      {"browser", ST_WEB_COLOR_TYPE_BROWSER},
      {"nil", ST_WEB_COLOR_TYPE_NIL},
      {"none", ST_WEB_COLOR_TYPE_NONE},
      {"presentationAccent", ST_WEB_COLOR_TYPE_PRESENTATION_ACCENT},
      {"presentationText", ST_WEB_COLOR_TYPE_PRESENTATION_TEXT},
      {"whiteTextOnBlack", ST_WEB_COLOR_TYPE_WHITE_TEXT_ON_BLACK}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_WEB_COLOR_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_WEB_COLOR_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

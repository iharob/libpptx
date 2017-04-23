#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-marker-style.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_marker_style_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_marker_style_text_enum
pptx_get_st_marker_style(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[13] = {
      {"auto", ST_MARKER_STYLE_AUTO},
      {"circle", ST_MARKER_STYLE_CIRCLE},
      {"dash", ST_MARKER_STYLE_DASH},
      {"diamond", ST_MARKER_STYLE_DIAMOND},
      {"dot", ST_MARKER_STYLE_DOT},
      {"nil", ST_MARKER_STYLE_NIL},
      {"none", ST_MARKER_STYLE_NONE},
      {"picture", ST_MARKER_STYLE_PICTURE},
      {"plus", ST_MARKER_STYLE_PLUS},
      {"square", ST_MARKER_STYLE_SQUARE},
      {"star", ST_MARKER_STYLE_STAR},
      {"triangle", ST_MARKER_STYLE_TRIANGLE},
      {"x", ST_MARKER_STYLE_X}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_MARKER_STYLE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 13, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_MARKER_STYLE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

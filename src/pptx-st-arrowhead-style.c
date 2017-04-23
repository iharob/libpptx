#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-arrowhead-style.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_arrowhead_style_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_arrowhead_style_token_enum
pptx_get_st_arrowhead_style(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"arr", ST_ARROWHEAD_STYLE_ARR},
      {"auto", ST_ARROWHEAD_STYLE_AUTO},
      {"nil", ST_ARROWHEAD_STYLE_NIL},
      {"noArr", ST_ARROWHEAD_STYLE_NO_ARR}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ARROWHEAD_STYLE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ARROWHEAD_STYLE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

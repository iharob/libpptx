#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-path-fill-mode.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_path_fill_mode_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_path_fill_mode_token_enum
pptx_get_st_path_fill_mode(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"darken", ST_PATH_FILL_MODE_DARKEN},
      {"darkenLess", ST_PATH_FILL_MODE_DARKEN_LESS},
      {"lighten", ST_PATH_FILL_MODE_LIGHTEN},
      {"lightenLess", ST_PATH_FILL_MODE_LIGHTEN_LESS},
      {"nil", ST_PATH_FILL_MODE_NIL},
      {"none", ST_PATH_FILL_MODE_NONE},
      {"norm", ST_PATH_FILL_MODE_NORM}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PATH_FILL_MODE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PATH_FILL_MODE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

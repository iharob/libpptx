#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tile-flip-mode.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tile_flip_mode_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tile_flip_mode_token_enum
pptx_get_st_tile_flip_mode(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"nil", ST_TILE_FLIP_MODE_NIL},
      {"none", ST_TILE_FLIP_MODE_NONE},
      {"x", ST_TILE_FLIP_MODE_X},
      {"xy", ST_TILE_FLIP_MODE_XY},
      {"y", ST_TILE_FLIP_MODE_Y}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TILE_FLIP_MODE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TILE_FLIP_MODE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

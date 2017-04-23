#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-pyramid-accent-position.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_pyramid_accent_position_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_pyramid_accent_position_token_enum
pptx_get_st_pyramid_accent_position(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"aft", ST_PYRAMID_ACCENT_POSITION_AFT},
      {"bef", ST_PYRAMID_ACCENT_POSITION_BEF},
      {"nil", ST_PYRAMID_ACCENT_POSITION_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PYRAMID_ACCENT_POSITION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PYRAMID_ACCENT_POSITION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

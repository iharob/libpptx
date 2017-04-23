#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-grow-direction.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_grow_direction_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_grow_direction_token_enum
pptx_get_st_grow_direction(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"bL", ST_GROW_DIRECTION_B_L},
      {"bR", ST_GROW_DIRECTION_B_R},
      {"nil", ST_GROW_DIRECTION_NIL},
      {"tL", ST_GROW_DIRECTION_T_L},
      {"tR", ST_GROW_DIRECTION_T_R}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_GROW_DIRECTION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_GROW_DIRECTION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

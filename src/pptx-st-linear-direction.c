#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-linear-direction.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_linear_direction_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_linear_direction_token_enum
pptx_get_st_linear_direction(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"fromB", ST_LINEAR_DIRECTION_FROM_B},
      {"fromL", ST_LINEAR_DIRECTION_FROM_L},
      {"fromR", ST_LINEAR_DIRECTION_FROM_R},
      {"fromT", ST_LINEAR_DIRECTION_FROM_T},
      {"nil", ST_LINEAR_DIRECTION_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_LINEAR_DIRECTION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_LINEAR_DIRECTION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

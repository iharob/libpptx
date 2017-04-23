#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-light-rig-direction.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_light_rig_direction_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_light_rig_direction_token_enum
pptx_get_st_light_rig_direction(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[9] = {
      {"b", ST_LIGHT_RIG_DIRECTION_B},
      {"bl", ST_LIGHT_RIG_DIRECTION_BL},
      {"br", ST_LIGHT_RIG_DIRECTION_BR},
      {"l", ST_LIGHT_RIG_DIRECTION_L},
      {"nil", ST_LIGHT_RIG_DIRECTION_NIL},
      {"r", ST_LIGHT_RIG_DIRECTION_R},
      {"t", ST_LIGHT_RIG_DIRECTION_T},
      {"tl", ST_LIGHT_RIG_DIRECTION_TL},
      {"tr", ST_LIGHT_RIG_DIRECTION_TR}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_LIGHT_RIG_DIRECTION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 9, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_LIGHT_RIG_DIRECTION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

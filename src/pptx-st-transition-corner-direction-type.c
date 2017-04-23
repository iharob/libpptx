#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-transition-corner-direction-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_transition_corner_direction_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_transition_corner_direction_type_token_enum
pptx_get_st_transition_corner_direction_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"ld", ST_TRANSITION_CORNER_DIRECTION_TYPE_LD},
      {"lu", ST_TRANSITION_CORNER_DIRECTION_TYPE_LU},
      {"nil", ST_TRANSITION_CORNER_DIRECTION_TYPE_NIL},
      {"rd", ST_TRANSITION_CORNER_DIRECTION_TYPE_RD},
      {"ru", ST_TRANSITION_CORNER_DIRECTION_TYPE_RU}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TRANSITION_CORNER_DIRECTION_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TRANSITION_CORNER_DIRECTION_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

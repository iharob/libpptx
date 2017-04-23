#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-transition-speed.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_transition_speed_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_transition_speed_token_enum
pptx_get_st_transition_speed(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"fast", ST_TRANSITION_SPEED_FAST},
      {"med", ST_TRANSITION_SPEED_MED},
      {"nil", ST_TRANSITION_SPEED_NIL},
      {"slow", ST_TRANSITION_SPEED_SLOW}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TRANSITION_SPEED_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TRANSITION_SPEED_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

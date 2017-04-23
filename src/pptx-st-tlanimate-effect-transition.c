#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tlanimate-effect-transition.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tlanimate_effect_transition_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tlanimate_effect_transition_token_enum
pptx_get_st_tlanimate_effect_transition(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"in", ST_TLANIMATE_EFFECT_TRANSITION_IN},
      {"nil", ST_TLANIMATE_EFFECT_TRANSITION_NIL},
      {"none", ST_TLANIMATE_EFFECT_TRANSITION_NONE},
      {"out", ST_TLANIMATE_EFFECT_TRANSITION_OUT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLANIMATE_EFFECT_TRANSITION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLANIMATE_EFFECT_TRANSITION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

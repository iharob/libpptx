#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tlanimate-behavior-calc-mode.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tlanimate_behavior_calc_mode_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tlanimate_behavior_calc_mode_token_enum
pptx_get_st_tlanimate_behavior_calc_mode(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"discrete", ST_TLANIMATE_BEHAVIOR_CALC_MODE_DISCRETE},
      {"fmla", ST_TLANIMATE_BEHAVIOR_CALC_MODE_FMLA},
      {"lin", ST_TLANIMATE_BEHAVIOR_CALC_MODE_LIN},
      {"nil", ST_TLANIMATE_BEHAVIOR_CALC_MODE_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLANIMATE_BEHAVIOR_CALC_MODE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLANIMATE_BEHAVIOR_CALC_MODE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

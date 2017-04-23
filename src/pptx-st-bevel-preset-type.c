#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-bevel-preset-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_bevel_preset_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_bevel_preset_type_token_enum
pptx_get_st_bevel_preset_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[13] = {
      {"angle", ST_BEVEL_PRESET_TYPE_ANGLE},
      {"artDeco", ST_BEVEL_PRESET_TYPE_ART_DECO},
      {"circle", ST_BEVEL_PRESET_TYPE_CIRCLE},
      {"convex", ST_BEVEL_PRESET_TYPE_CONVEX},
      {"coolSlant", ST_BEVEL_PRESET_TYPE_COOL_SLANT},
      {"cross", ST_BEVEL_PRESET_TYPE_CROSS},
      {"divot", ST_BEVEL_PRESET_TYPE_DIVOT},
      {"hardEdge", ST_BEVEL_PRESET_TYPE_HARD_EDGE},
      {"nil", ST_BEVEL_PRESET_TYPE_NIL},
      {"relaxedInset", ST_BEVEL_PRESET_TYPE_RELAXED_INSET},
      {"riblet", ST_BEVEL_PRESET_TYPE_RIBLET},
      {"slope", ST_BEVEL_PRESET_TYPE_SLOPE},
      {"softRound", ST_BEVEL_PRESET_TYPE_SOFT_ROUND}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_BEVEL_PRESET_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 13, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_BEVEL_PRESET_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

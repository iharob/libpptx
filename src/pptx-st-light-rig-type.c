#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-light-rig-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_light_rig_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_light_rig_type_token_enum
pptx_get_st_light_rig_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[28] = {
      {"balanced", ST_LIGHT_RIG_TYPE_BALANCED},
      {"brightRoom", ST_LIGHT_RIG_TYPE_BRIGHT_ROOM},
      {"chilly", ST_LIGHT_RIG_TYPE_CHILLY},
      {"contrasting", ST_LIGHT_RIG_TYPE_CONTRASTING},
      {"flat", ST_LIGHT_RIG_TYPE_FLAT},
      {"flood", ST_LIGHT_RIG_TYPE_FLOOD},
      {"freezing", ST_LIGHT_RIG_TYPE_FREEZING},
      {"glow", ST_LIGHT_RIG_TYPE_GLOW},
      {"harsh", ST_LIGHT_RIG_TYPE_HARSH},
      {"legacyFlat1", ST_LIGHT_RIG_TYPE_LEGACY_FLAT1},
      {"legacyFlat2", ST_LIGHT_RIG_TYPE_LEGACY_FLAT2},
      {"legacyFlat3", ST_LIGHT_RIG_TYPE_LEGACY_FLAT3},
      {"legacyFlat4", ST_LIGHT_RIG_TYPE_LEGACY_FLAT4},
      {"legacyHarsh1", ST_LIGHT_RIG_TYPE_LEGACY_HARSH1},
      {"legacyHarsh2", ST_LIGHT_RIG_TYPE_LEGACY_HARSH2},
      {"legacyHarsh3", ST_LIGHT_RIG_TYPE_LEGACY_HARSH3},
      {"legacyHarsh4", ST_LIGHT_RIG_TYPE_LEGACY_HARSH4},
      {"legacyNormal1", ST_LIGHT_RIG_TYPE_LEGACY_NORMAL1},
      {"legacyNormal2", ST_LIGHT_RIG_TYPE_LEGACY_NORMAL2},
      {"legacyNormal3", ST_LIGHT_RIG_TYPE_LEGACY_NORMAL3},
      {"legacyNormal4", ST_LIGHT_RIG_TYPE_LEGACY_NORMAL4},
      {"morning", ST_LIGHT_RIG_TYPE_MORNING},
      {"nil", ST_LIGHT_RIG_TYPE_NIL},
      {"soft", ST_LIGHT_RIG_TYPE_SOFT},
      {"sunrise", ST_LIGHT_RIG_TYPE_SUNRISE},
      {"sunset", ST_LIGHT_RIG_TYPE_SUNSET},
      {"threePt", ST_LIGHT_RIG_TYPE_THREE_PT},
      {"twoPt", ST_LIGHT_RIG_TYPE_TWO_PT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_LIGHT_RIG_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 28, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_LIGHT_RIG_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

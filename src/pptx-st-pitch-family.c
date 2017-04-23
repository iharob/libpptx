#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-pitch-family.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_pitch_family_byte_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_pitch_family_byte_enum
pptx_get_st_pitch_family(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[19] = {
      {"00", ST_PITCH_FAMILY_00},
      {"01", ST_PITCH_FAMILY_01},
      {"02", ST_PITCH_FAMILY_02},
      {"16", ST_PITCH_FAMILY_16},
      {"17", ST_PITCH_FAMILY_17},
      {"18", ST_PITCH_FAMILY_18},
      {"32", ST_PITCH_FAMILY_32},
      {"33", ST_PITCH_FAMILY_33},
      {"34", ST_PITCH_FAMILY_34},
      {"48", ST_PITCH_FAMILY_48},
      {"49", ST_PITCH_FAMILY_49},
      {"50", ST_PITCH_FAMILY_50},
      {"64", ST_PITCH_FAMILY_64},
      {"65", ST_PITCH_FAMILY_65},
      {"66", ST_PITCH_FAMILY_66},
      {"80", ST_PITCH_FAMILY_80},
      {"81", ST_PITCH_FAMILY_81},
      {"82", ST_PITCH_FAMILY_82},
      {"nil", ST_PITCH_FAMILY_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PITCH_FAMILY_NIL;
    // Perform binary search
    found = bsearch(&key, base, 19, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PITCH_FAMILY_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

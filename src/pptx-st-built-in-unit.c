#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-built-in-unit.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_built_in_unit_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_built_in_unit_text_enum
pptx_get_st_built_in_unit(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[10] = {
      {"billions", ST_BUILT_IN_UNIT_BILLIONS},
      {"hundredMillions", ST_BUILT_IN_UNIT_HUNDRED_MILLIONS},
      {"hundredThousands", ST_BUILT_IN_UNIT_HUNDRED_THOUSANDS},
      {"hundreds", ST_BUILT_IN_UNIT_HUNDREDS},
      {"millions", ST_BUILT_IN_UNIT_MILLIONS},
      {"nil", ST_BUILT_IN_UNIT_NIL},
      {"tenMillions", ST_BUILT_IN_UNIT_TEN_MILLIONS},
      {"tenThousands", ST_BUILT_IN_UNIT_TEN_THOUSANDS},
      {"thousands", ST_BUILT_IN_UNIT_THOUSANDS},
      {"trillions", ST_BUILT_IN_UNIT_TRILLIONS}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_BUILT_IN_UNIT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 10, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_BUILT_IN_UNIT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

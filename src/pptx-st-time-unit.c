#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-time-unit.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_time_unit_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_time_unit_text_enum
pptx_get_st_time_unit(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"days", ST_TIME_UNIT_DAYS},
      {"months", ST_TIME_UNIT_MONTHS},
      {"nil", ST_TIME_UNIT_NIL},
      {"years", ST_TIME_UNIT_YEARS}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TIME_UNIT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TIME_UNIT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

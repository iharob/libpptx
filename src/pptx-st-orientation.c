#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-orientation.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_orientation_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_orientation_text_enum
pptx_get_st_orientation(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"maxMin", ST_ORIENTATION_MAX_MIN},
      {"minMax", ST_ORIENTATION_MIN_MAX},
      {"nil", ST_ORIENTATION_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ORIENTATION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ORIENTATION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

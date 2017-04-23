#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-crosses.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_crosses_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_crosses_text_enum
pptx_get_st_crosses(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"autoZero", ST_CROSSES_AUTO_ZERO},
      {"max", ST_CROSSES_MAX},
      {"min", ST_CROSSES_MIN},
      {"nil", ST_CROSSES_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CROSSES_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CROSSES_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

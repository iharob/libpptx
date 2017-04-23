#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-placeholder-size.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_placeholder_size_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_placeholder_size_token_enum
pptx_get_st_placeholder_size(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"full", ST_PLACEHOLDER_SIZE_FULL},
      {"half", ST_PLACEHOLDER_SIZE_HALF},
      {"nil", ST_PLACEHOLDER_SIZE_NIL},
      {"quarter", ST_PLACEHOLDER_SIZE_QUARTER}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PLACEHOLDER_SIZE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PLACEHOLDER_SIZE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

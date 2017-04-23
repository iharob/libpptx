#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tltime-indefinite.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tltime_indefinite_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tltime_indefinite_token_enum
pptx_get_st_tltime_indefinite(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[2] = {
      {"indefinite", ST_TLTIME_INDEFINITE_INDEFINITE},
      {"nil", ST_TLTIME_INDEFINITE_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLTIME_INDEFINITE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 2, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLTIME_INDEFINITE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

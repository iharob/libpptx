#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-cross-between.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_cross_between_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_cross_between_text_enum
pptx_get_st_cross_between(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"between", ST_CROSS_BETWEEN_BETWEEN},
      {"midCat", ST_CROSS_BETWEEN_MID_CAT},
      {"nil", ST_CROSS_BETWEEN_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CROSS_BETWEEN_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CROSS_BETWEEN_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

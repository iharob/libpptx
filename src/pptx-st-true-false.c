#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-true-false.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_true_false_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_true_false_text_enum
pptx_get_st_true_false(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"f", ST_TRUE_FALSE_F},
      {"false", ST_TRUE_FALSE_FALSE},
      {"nil", ST_TRUE_FALSE_NIL},
      {"t", ST_TRUE_FALSE_T},
      {"true", ST_TRUE_FALSE_TRUE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TRUE_FALSE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TRUE_FALSE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

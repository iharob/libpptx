#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-alg-class.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_alg_class_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_alg_class_text_enum
pptx_get_st_alg_class(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"custom", ST_ALG_CLASS_CUSTOM},
      {"hash", ST_ALG_CLASS_HASH},
      {"nil", ST_ALG_CLASS_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ALG_CLASS_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ALG_CLASS_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

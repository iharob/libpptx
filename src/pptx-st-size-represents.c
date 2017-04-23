#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-size-represents.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_size_represents_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_size_represents_text_enum
pptx_get_st_size_represents(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"area", ST_SIZE_REPRESENTS_AREA},
      {"nil", ST_SIZE_REPRESENTS_NIL},
      {"w", ST_SIZE_REPRESENTS_W}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_SIZE_REPRESENTS_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_SIZE_REPRESENTS_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

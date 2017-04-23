#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-starting-element.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_starting_element_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_starting_element_token_enum
pptx_get_st_starting_element(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"nil", ST_STARTING_ELEMENT_NIL},
      {"node", ST_STARTING_ELEMENT_NODE},
      {"trans", ST_STARTING_ELEMENT_TRANS}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_STARTING_ELEMENT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_STARTING_ELEMENT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-xalign.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_xalign_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_xalign_text_enum
pptx_get_st_xalign(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[6] = {
      {"center", ST_XALIGN_CENTER},
      {"inside", ST_XALIGN_INSIDE},
      {"left", ST_XALIGN_LEFT},
      {"nil", ST_XALIGN_NIL},
      {"outside", ST_XALIGN_OUTSIDE},
      {"right", ST_XALIGN_RIGHT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_XALIGN_NIL;
    // Perform binary search
    found = bsearch(&key, base, 6, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_XALIGN_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

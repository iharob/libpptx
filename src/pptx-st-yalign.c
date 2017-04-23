#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-yalign.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_yalign_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_yalign_text_enum
pptx_get_st_yalign(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"bottom", ST_YALIGN_BOTTOM},
      {"center", ST_YALIGN_CENTER},
      {"inline", ST_YALIGN_INLINE},
      {"inside", ST_YALIGN_INSIDE},
      {"nil", ST_YALIGN_NIL},
      {"outside", ST_YALIGN_OUTSIDE},
      {"top", ST_YALIGN_TOP}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_YALIGN_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_YALIGN_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

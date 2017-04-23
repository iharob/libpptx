#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-layout-target.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_layout_target_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_layout_target_text_enum
pptx_get_st_layout_target(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"inner", ST_LAYOUT_TARGET_INNER},
      {"nil", ST_LAYOUT_TARGET_NIL},
      {"outer", ST_LAYOUT_TARGET_OUTER}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_LAYOUT_TARGET_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_LAYOUT_TARGET_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

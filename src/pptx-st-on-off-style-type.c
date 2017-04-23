#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-on-off-style-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_on_off_style_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_on_off_style_type_token_enum
pptx_get_st_on_off_style_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"def", ST_ON_OFF_STYLE_TYPE_DEF},
      {"nil", ST_ON_OFF_STYLE_TYPE_NIL},
      {"off", ST_ON_OFF_STYLE_TYPE_OFF},
      {"on", ST_ON_OFF_STYLE_TYPE_ON}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ON_OFF_STYLE_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ON_OFF_STYLE_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

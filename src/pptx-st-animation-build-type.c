#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-animation-build-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_animation_build_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_animation_build_type_token_enum
pptx_get_st_animation_build_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[2] = {
      {"allAtOnce", ST_ANIMATION_BUILD_TYPE_ALL_AT_ONCE},
      {"nil", ST_ANIMATION_BUILD_TYPE_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ANIMATION_BUILD_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 2, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ANIMATION_BUILD_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

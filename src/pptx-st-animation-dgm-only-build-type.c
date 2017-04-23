#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-animation-dgm-only-build-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_animation_dgm_only_build_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_animation_dgm_only_build_type_token_enum
pptx_get_st_animation_dgm_only_build_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"lvlAtOnce", ST_ANIMATION_DGM_ONLY_BUILD_TYPE_LVL_AT_ONCE},
      {"lvlOne", ST_ANIMATION_DGM_ONLY_BUILD_TYPE_LVL_ONE},
      {"nil", ST_ANIMATION_DGM_ONLY_BUILD_TYPE_NIL},
      {"one", ST_ANIMATION_DGM_ONLY_BUILD_TYPE_ONE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ANIMATION_DGM_ONLY_BUILD_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ANIMATION_DGM_ONLY_BUILD_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

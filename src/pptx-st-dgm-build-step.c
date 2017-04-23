#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-dgm-build-step.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_dgm_build_step_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_dgm_build_step_token_enum
pptx_get_st_dgm_build_step(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"bg", ST_DGM_BUILD_STEP_BG},
      {"nil", ST_DGM_BUILD_STEP_NIL},
      {"sp", ST_DGM_BUILD_STEP_SP}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_DGM_BUILD_STEP_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_DGM_BUILD_STEP_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

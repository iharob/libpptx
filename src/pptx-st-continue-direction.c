#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-continue-direction.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_continue_direction_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_continue_direction_token_enum
pptx_get_st_continue_direction(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"nil", ST_CONTINUE_DIRECTION_NIL},
      {"revDir", ST_CONTINUE_DIRECTION_REV_DIR},
      {"sameDir", ST_CONTINUE_DIRECTION_SAME_DIR}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CONTINUE_DIRECTION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CONTINUE_DIRECTION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

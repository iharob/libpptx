#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-hue-dir.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_hue_dir_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_hue_dir_token_enum
pptx_get_st_hue_dir(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"ccw", ST_HUE_DIR_CCW},
      {"cw", ST_HUE_DIR_CW},
      {"nil", ST_HUE_DIR_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_HUE_DIR_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_HUE_DIR_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

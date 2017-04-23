#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-blend-mode.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_blend_mode_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_blend_mode_token_enum
pptx_get_st_blend_mode(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[6] = {
      {"darken", ST_BLEND_MODE_DARKEN},
      {"lighten", ST_BLEND_MODE_LIGHTEN},
      {"mult", ST_BLEND_MODE_MULT},
      {"nil", ST_BLEND_MODE_NIL},
      {"over", ST_BLEND_MODE_OVER},
      {"screen", ST_BLEND_MODE_SCREEN}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_BLEND_MODE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 6, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_BLEND_MODE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

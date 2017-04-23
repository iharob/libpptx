#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-auto-text-rotation.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_auto_text_rotation_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_auto_text_rotation_token_enum
pptx_get_st_auto_text_rotation(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"grav", ST_AUTO_TEXT_ROTATION_GRAV},
      {"nil", ST_AUTO_TEXT_ROTATION_NIL},
      {"none", ST_AUTO_TEXT_ROTATION_NONE},
      {"upr", ST_AUTO_TEXT_ROTATION_UPR}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_AUTO_TEXT_ROTATION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_AUTO_TEXT_ROTATION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

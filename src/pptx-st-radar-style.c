#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-radar-style.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_radar_style_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_radar_style_text_enum
pptx_get_st_radar_style(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"filled", ST_RADAR_STYLE_FILLED},
      {"marker", ST_RADAR_STYLE_MARKER},
      {"nil", ST_RADAR_STYLE_NIL},
      {"standard", ST_RADAR_STYLE_STANDARD}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_RADAR_STYLE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_RADAR_STYLE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-scatter-style.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_scatter_style_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_scatter_style_text_enum
pptx_get_st_scatter_style(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"line", ST_SCATTER_STYLE_LINE},
      {"lineMarker", ST_SCATTER_STYLE_LINE_MARKER},
      {"marker", ST_SCATTER_STYLE_MARKER},
      {"nil", ST_SCATTER_STYLE_NIL},
      {"none", ST_SCATTER_STYLE_NONE},
      {"smooth", ST_SCATTER_STYLE_SMOOTH},
      {"smoothMarker", ST_SCATTER_STYLE_SMOOTH_MARKER}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_SCATTER_STYLE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_SCATTER_STYLE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

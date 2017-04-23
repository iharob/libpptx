#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-color-scheme-index.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_color_scheme_index_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_color_scheme_index_token_enum
pptx_get_st_color_scheme_index(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[13] = {
      {"accent1", ST_COLOR_SCHEME_INDEX_ACCENT1},
      {"accent2", ST_COLOR_SCHEME_INDEX_ACCENT2},
      {"accent3", ST_COLOR_SCHEME_INDEX_ACCENT3},
      {"accent4", ST_COLOR_SCHEME_INDEX_ACCENT4},
      {"accent5", ST_COLOR_SCHEME_INDEX_ACCENT5},
      {"accent6", ST_COLOR_SCHEME_INDEX_ACCENT6},
      {"dk1", ST_COLOR_SCHEME_INDEX_DK1},
      {"dk2", ST_COLOR_SCHEME_INDEX_DK2},
      {"folHlink", ST_COLOR_SCHEME_INDEX_FOL_HLINK},
      {"hlink", ST_COLOR_SCHEME_INDEX_HLINK},
      {"lt1", ST_COLOR_SCHEME_INDEX_LT1},
      {"lt2", ST_COLOR_SCHEME_INDEX_LT2},
      {"nil", ST_COLOR_SCHEME_INDEX_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_COLOR_SCHEME_INDEX_NIL;
    // Perform binary search
    found = bsearch(&key, base, 13, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_COLOR_SCHEME_INDEX_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

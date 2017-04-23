#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-scheme-color-val.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_scheme_color_val_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_scheme_color_val_token_enum
pptx_get_st_scheme_color_val(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[18] = {
      {"accent1", ST_SCHEME_COLOR_VAL_ACCENT1},
      {"accent2", ST_SCHEME_COLOR_VAL_ACCENT2},
      {"accent3", ST_SCHEME_COLOR_VAL_ACCENT3},
      {"accent4", ST_SCHEME_COLOR_VAL_ACCENT4},
      {"accent5", ST_SCHEME_COLOR_VAL_ACCENT5},
      {"accent6", ST_SCHEME_COLOR_VAL_ACCENT6},
      {"bg1", ST_SCHEME_COLOR_VAL_BG1},
      {"bg2", ST_SCHEME_COLOR_VAL_BG2},
      {"dk1", ST_SCHEME_COLOR_VAL_DK1},
      {"dk2", ST_SCHEME_COLOR_VAL_DK2},
      {"folHlink", ST_SCHEME_COLOR_VAL_FOL_HLINK},
      {"hlink", ST_SCHEME_COLOR_VAL_HLINK},
      {"lt1", ST_SCHEME_COLOR_VAL_LT1},
      {"lt2", ST_SCHEME_COLOR_VAL_LT2},
      {"nil", ST_SCHEME_COLOR_VAL_NIL},
      {"phClr", ST_SCHEME_COLOR_VAL_PH_CLR},
      {"tx1", ST_SCHEME_COLOR_VAL_TX1},
      {"tx2", ST_SCHEME_COLOR_VAL_TX2}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_SCHEME_COLOR_VAL_NIL;
    // Perform binary search
    found = bsearch(&key, base, 18, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_SCHEME_COLOR_VAL_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

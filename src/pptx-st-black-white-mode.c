#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-black-white-mode.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_black_white_mode_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_black_white_mode_token_enum
pptx_get_st_black_white_mode(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[12] = {
      {"auto", ST_BLACK_WHITE_MODE_AUTO},
      {"black", ST_BLACK_WHITE_MODE_BLACK},
      {"blackGray", ST_BLACK_WHITE_MODE_BLACK_GRAY},
      {"blackWhite", ST_BLACK_WHITE_MODE_BLACK_WHITE},
      {"clr", ST_BLACK_WHITE_MODE_CLR},
      {"gray", ST_BLACK_WHITE_MODE_GRAY},
      {"grayWhite", ST_BLACK_WHITE_MODE_GRAY_WHITE},
      {"hidden", ST_BLACK_WHITE_MODE_HIDDEN},
      {"invGray", ST_BLACK_WHITE_MODE_INV_GRAY},
      {"ltGray", ST_BLACK_WHITE_MODE_LT_GRAY},
      {"nil", ST_BLACK_WHITE_MODE_NIL},
      {"white", ST_BLACK_WHITE_MODE_WHITE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_BLACK_WHITE_MODE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 12, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_BLACK_WHITE_MODE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

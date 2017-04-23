#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-slide-size-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_slide_size_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_slide_size_type_token_enum
pptx_get_st_slide_size_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[17] = {
      {"35mm", ST_SLIDE_SIZE_TYPE_35MM},
      {"A3", ST_SLIDE_SIZE_TYPE_A3},
      {"A4", ST_SLIDE_SIZE_TYPE_A4},
      {"B4ISO", ST_SLIDE_SIZE_TYPE_B4_ISO},
      {"B4JIS", ST_SLIDE_SIZE_TYPE_B4_JIS},
      {"B5ISO", ST_SLIDE_SIZE_TYPE_B5_ISO},
      {"B5JIS", ST_SLIDE_SIZE_TYPE_B5_JIS},
      {"banner", ST_SLIDE_SIZE_TYPE_BANNER},
      {"custom", ST_SLIDE_SIZE_TYPE_CUSTOM},
      {"hagakiCard", ST_SLIDE_SIZE_TYPE_HAGAKI_CARD},
      {"ledger", ST_SLIDE_SIZE_TYPE_LEDGER},
      {"letter", ST_SLIDE_SIZE_TYPE_LETTER},
      {"nil", ST_SLIDE_SIZE_TYPE_NIL},
      {"overhead", ST_SLIDE_SIZE_TYPE_OVERHEAD},
      {"screen16x10", ST_SLIDE_SIZE_TYPE_SCREEN16X10},
      {"screen16x9", ST_SLIDE_SIZE_TYPE_SCREEN16X9},
      {"screen4x3", ST_SLIDE_SIZE_TYPE_SCREEN4X3}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_SLIDE_SIZE_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 17, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_SLIDE_SIZE_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

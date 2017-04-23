#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-text-vertical-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_text_vertical_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_text_vertical_type_token_enum
pptx_get_st_text_vertical_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[8] = {
      {"eaVert", ST_TEXT_VERTICAL_TYPE_EA_VERT},
      {"horz", ST_TEXT_VERTICAL_TYPE_HORZ},
      {"mongolianVert", ST_TEXT_VERTICAL_TYPE_MONGOLIAN_VERT},
      {"nil", ST_TEXT_VERTICAL_TYPE_NIL},
      {"vert", ST_TEXT_VERTICAL_TYPE_VERT},
      {"vert270", ST_TEXT_VERTICAL_TYPE_VERT270},
      {"wordArtVert", ST_TEXT_VERTICAL_TYPE_WORD_ART_VERT},
      {"wordArtVertRtl", ST_TEXT_VERTICAL_TYPE_WORD_ART_VERT_RTL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TEXT_VERTICAL_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 8, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TEXT_VERTICAL_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

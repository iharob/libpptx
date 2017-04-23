#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-rect-alignment.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_rect_alignment_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_rect_alignment_token_enum
pptx_get_st_rect_alignment(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[10] = {
      {"b", ST_RECT_ALIGNMENT_B},
      {"bl", ST_RECT_ALIGNMENT_BL},
      {"br", ST_RECT_ALIGNMENT_BR},
      {"ctr", ST_RECT_ALIGNMENT_CTR},
      {"l", ST_RECT_ALIGNMENT_L},
      {"nil", ST_RECT_ALIGNMENT_NIL},
      {"r", ST_RECT_ALIGNMENT_R},
      {"t", ST_RECT_ALIGNMENT_T},
      {"tl", ST_RECT_ALIGNMENT_TL},
      {"tr", ST_RECT_ALIGNMENT_TR}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_RECT_ALIGNMENT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 10, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_RECT_ALIGNMENT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

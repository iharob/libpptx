#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-vertical-alignment.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_vertical_alignment_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_vertical_alignment_token_enum
pptx_get_st_vertical_alignment(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"b", ST_VERTICAL_ALIGNMENT_B},
      {"mid", ST_VERTICAL_ALIGNMENT_MID},
      {"nil", ST_VERTICAL_ALIGNMENT_NIL},
      {"none", ST_VERTICAL_ALIGNMENT_NONE},
      {"t", ST_VERTICAL_ALIGNMENT_T}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_VERTICAL_ALIGNMENT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_VERTICAL_ALIGNMENT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

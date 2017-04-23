#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-ax-pos.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_ax_pos_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_ax_pos_text_enum
pptx_get_st_ax_pos(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"b", ST_AX_POS_B},
      {"l", ST_AX_POS_L},
      {"nil", ST_AX_POS_NIL},
      {"r", ST_AX_POS_R},
      {"t", ST_AX_POS_T}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_AX_POS_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_AX_POS_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

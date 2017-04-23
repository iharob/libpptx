#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-dlbl-pos.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_dlbl_pos_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_dlbl_pos_text_enum
pptx_get_st_dlbl_pos(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[10] = {
      {"b", ST_DLBL_POS_B},
      {"bestFit", ST_DLBL_POS_BEST_FIT},
      {"ctr", ST_DLBL_POS_CTR},
      {"inBase", ST_DLBL_POS_IN_BASE},
      {"inEnd", ST_DLBL_POS_IN_END},
      {"l", ST_DLBL_POS_L},
      {"nil", ST_DLBL_POS_NIL},
      {"outEnd", ST_DLBL_POS_OUT_END},
      {"r", ST_DLBL_POS_R},
      {"t", ST_DLBL_POS_T}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_DLBL_POS_NIL;
    // Perform binary search
    found = bsearch(&key, base, 10, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_DLBL_POS_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

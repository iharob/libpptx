#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tick-lbl-pos.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tick_lbl_pos_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tick_lbl_pos_text_enum
pptx_get_st_tick_lbl_pos(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"high", ST_TICK_LBL_POS_HIGH},
      {"low", ST_TICK_LBL_POS_LOW},
      {"nextTo", ST_TICK_LBL_POS_NEXT_TO},
      {"nil", ST_TICK_LBL_POS_NIL},
      {"none", ST_TICK_LBL_POS_NONE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TICK_LBL_POS_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TICK_LBL_POS_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

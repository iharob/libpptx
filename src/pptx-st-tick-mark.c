#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tick-mark.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tick_mark_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tick_mark_text_enum
pptx_get_st_tick_mark(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"cross", ST_TICK_MARK_CROSS},
      {"in", ST_TICK_MARK_IN},
      {"nil", ST_TICK_MARK_NIL},
      {"none", ST_TICK_MARK_NONE},
      {"out", ST_TICK_MARK_OUT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TICK_MARK_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TICK_MARK_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

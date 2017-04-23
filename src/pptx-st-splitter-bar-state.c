#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-splitter-bar-state.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_splitter_bar_state_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_splitter_bar_state_token_enum
pptx_get_st_splitter_bar_state(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"maximized", ST_SPLITTER_BAR_STATE_MAXIMIZED},
      {"minimized", ST_SPLITTER_BAR_STATE_MINIMIZED},
      {"nil", ST_SPLITTER_BAR_STATE_NIL},
      {"restored", ST_SPLITTER_BAR_STATE_RESTORED}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_SPLITTER_BAR_STATE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_SPLITTER_BAR_STATE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

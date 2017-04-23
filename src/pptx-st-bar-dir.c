#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-bar-dir.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_bar_dir_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_bar_dir_text_enum
pptx_get_st_bar_dir(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"bar", ST_BAR_DIR_BAR},
      {"col", ST_BAR_DIR_COL},
      {"nil", ST_BAR_DIR_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_BAR_DIR_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_BAR_DIR_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

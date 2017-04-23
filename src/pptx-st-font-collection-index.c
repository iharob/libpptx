#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-font-collection-index.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_font_collection_index_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_font_collection_index_token_enum
pptx_get_st_font_collection_index(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"major", ST_FONT_COLLECTION_INDEX_MAJOR},
      {"minor", ST_FONT_COLLECTION_INDEX_MINOR},
      {"nil", ST_FONT_COLLECTION_INDEX_NIL},
      {"none", ST_FONT_COLLECTION_INDEX_NONE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_FONT_COLLECTION_INDEX_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_FONT_COLLECTION_INDEX_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

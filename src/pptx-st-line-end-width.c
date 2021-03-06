#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-line-end-width.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_line_end_width_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_line_end_width_token_enum
pptx_get_st_line_end_width(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"lg", ST_LINE_END_WIDTH_LG},
      {"med", ST_LINE_END_WIDTH_MED},
      {"nil", ST_LINE_END_WIDTH_NIL},
      {"sm", ST_LINE_END_WIDTH_SM}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_LINE_END_WIDTH_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_LINE_END_WIDTH_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

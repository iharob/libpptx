#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-line-end-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_line_end_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_line_end_type_token_enum
pptx_get_st_line_end_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"arrow", ST_LINE_END_TYPE_ARROW},
      {"diamond", ST_LINE_END_TYPE_DIAMOND},
      {"nil", ST_LINE_END_TYPE_NIL},
      {"none", ST_LINE_END_TYPE_NONE},
      {"oval", ST_LINE_END_TYPE_OVAL},
      {"stealth", ST_LINE_END_TYPE_STEALTH},
      {"triangle", ST_LINE_END_TYPE_TRIANGLE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_LINE_END_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_LINE_END_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

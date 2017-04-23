#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-line-cap.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_line_cap_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_line_cap_token_enum
pptx_get_st_line_cap(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"flat", ST_LINE_CAP_FLAT},
      {"nil", ST_LINE_CAP_NIL},
      {"rnd", ST_LINE_CAP_RND},
      {"sq", ST_LINE_CAP_SQ}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_LINE_CAP_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_LINE_CAP_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

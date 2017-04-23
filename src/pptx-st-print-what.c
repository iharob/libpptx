#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-print-what.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_print_what_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_print_what_token_enum
pptx_get_st_print_what(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[10] = {
      {"handouts1", ST_PRINT_WHAT_HANDOUTS1},
      {"handouts2", ST_PRINT_WHAT_HANDOUTS2},
      {"handouts3", ST_PRINT_WHAT_HANDOUTS3},
      {"handouts4", ST_PRINT_WHAT_HANDOUTS4},
      {"handouts6", ST_PRINT_WHAT_HANDOUTS6},
      {"handouts9", ST_PRINT_WHAT_HANDOUTS9},
      {"nil", ST_PRINT_WHAT_NIL},
      {"notes", ST_PRINT_WHAT_NOTES},
      {"outline", ST_PRINT_WHAT_OUTLINE},
      {"slides", ST_PRINT_WHAT_SLIDES}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PRINT_WHAT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 10, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PRINT_WHAT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

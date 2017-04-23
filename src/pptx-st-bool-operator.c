#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-bool-operator.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_bool_operator_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_bool_operator_token_enum
pptx_get_st_bool_operator(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"equ", ST_BOOL_OPERATOR_EQU},
      {"gte", ST_BOOL_OPERATOR_GTE},
      {"lte", ST_BOOL_OPERATOR_LTE},
      {"nil", ST_BOOL_OPERATOR_NIL},
      {"none", ST_BOOL_OPERATOR_NONE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_BOOL_OPERATOR_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_BOOL_OPERATOR_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

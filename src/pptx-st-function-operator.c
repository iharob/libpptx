#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-function-operator.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_function_operator_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_function_operator_token_enum
pptx_get_st_function_operator(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"equ", ST_FUNCTION_OPERATOR_EQU},
      {"gt", ST_FUNCTION_OPERATOR_GT},
      {"gte", ST_FUNCTION_OPERATOR_GTE},
      {"lt", ST_FUNCTION_OPERATOR_LT},
      {"lte", ST_FUNCTION_OPERATOR_LTE},
      {"neq", ST_FUNCTION_OPERATOR_NEQ},
      {"nil", ST_FUNCTION_OPERATOR_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_FUNCTION_OPERATOR_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_FUNCTION_OPERATOR_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

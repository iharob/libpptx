#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-function-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_function_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_function_type_token_enum
pptx_get_st_function_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[9] = {
      {"cnt", ST_FUNCTION_TYPE_CNT},
      {"depth", ST_FUNCTION_TYPE_DEPTH},
      {"maxDepth", ST_FUNCTION_TYPE_MAX_DEPTH},
      {"nil", ST_FUNCTION_TYPE_NIL},
      {"pos", ST_FUNCTION_TYPE_POS},
      {"posEven", ST_FUNCTION_TYPE_POS_EVEN},
      {"posOdd", ST_FUNCTION_TYPE_POS_ODD},
      {"revPos", ST_FUNCTION_TYPE_REV_POS},
      {"var", ST_FUNCTION_TYPE_VAR}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_FUNCTION_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 9, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_FUNCTION_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

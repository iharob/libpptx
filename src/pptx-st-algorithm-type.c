#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-algorithm-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_algorithm_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_algorithm_type_token_enum
pptx_get_st_algorithm_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[11] = {
      {"composite", ST_ALGORITHM_TYPE_COMPOSITE},
      {"conn", ST_ALGORITHM_TYPE_CONN},
      {"cycle", ST_ALGORITHM_TYPE_CYCLE},
      {"hierChild", ST_ALGORITHM_TYPE_HIER_CHILD},
      {"hierRoot", ST_ALGORITHM_TYPE_HIER_ROOT},
      {"lin", ST_ALGORITHM_TYPE_LIN},
      {"nil", ST_ALGORITHM_TYPE_NIL},
      {"pyra", ST_ALGORITHM_TYPE_PYRA},
      {"snake", ST_ALGORITHM_TYPE_SNAKE},
      {"sp", ST_ALGORITHM_TYPE_SP},
      {"tx", ST_ALGORITHM_TYPE_TX}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ALGORITHM_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 11, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ALGORITHM_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

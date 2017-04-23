#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-cxn-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_cxn_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_cxn_type_token_enum
pptx_get_st_cxn_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"nil", ST_CXN_TYPE_NIL},
      {"parOf", ST_CXN_TYPE_PAR_OF},
      {"presOf", ST_CXN_TYPE_PRES_OF},
      {"presParOf", ST_CXN_TYPE_PRES_PAR_OF},
      {"unknownRelationship", ST_CXN_TYPE_UNKNOWN_RELATIONSHIP}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CXN_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CXN_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

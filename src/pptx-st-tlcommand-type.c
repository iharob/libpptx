#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tlcommand-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tlcommand_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tlcommand_type_token_enum
pptx_get_st_tlcommand_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"call", ST_TLCOMMAND_TYPE_CALL},
      {"evt", ST_TLCOMMAND_TYPE_EVT},
      {"nil", ST_TLCOMMAND_TYPE_NIL},
      {"verb", ST_TLCOMMAND_TYPE_VERB}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLCOMMAND_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLCOMMAND_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

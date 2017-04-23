#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-constraint-relationship.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_constraint_relationship_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_constraint_relationship_token_enum
pptx_get_st_constraint_relationship(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"ch", ST_CONSTRAINT_RELATIONSHIP_CH},
      {"des", ST_CONSTRAINT_RELATIONSHIP_DES},
      {"nil", ST_CONSTRAINT_RELATIONSHIP_NIL},
      {"self", ST_CONSTRAINT_RELATIONSHIP_SELF}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CONSTRAINT_RELATIONSHIP_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CONSTRAINT_RELATIONSHIP_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

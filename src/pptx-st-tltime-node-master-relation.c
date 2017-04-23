#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tltime-node-master-relation.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tltime_node_master_relation_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tltime_node_master_relation_token_enum
pptx_get_st_tltime_node_master_relation(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"lastClick", ST_TLTIME_NODE_MASTER_RELATION_LAST_CLICK},
      {"nextClick", ST_TLTIME_NODE_MASTER_RELATION_NEXT_CLICK},
      {"nil", ST_TLTIME_NODE_MASTER_RELATION_NIL},
      {"sameClick", ST_TLTIME_NODE_MASTER_RELATION_SAME_CLICK}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLTIME_NODE_MASTER_RELATION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLTIME_NODE_MASTER_RELATION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

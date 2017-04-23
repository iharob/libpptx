#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tltime-node-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tltime_node_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tltime_node_type_token_enum
pptx_get_st_tltime_node_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[10] = {
      {"afterEffect", ST_TLTIME_NODE_TYPE_AFTER_EFFECT},
      {"afterGroup", ST_TLTIME_NODE_TYPE_AFTER_GROUP},
      {"clickEffect", ST_TLTIME_NODE_TYPE_CLICK_EFFECT},
      {"clickPar", ST_TLTIME_NODE_TYPE_CLICK_PAR},
      {"interactiveSeq", ST_TLTIME_NODE_TYPE_INTERACTIVE_SEQ},
      {"mainSeq", ST_TLTIME_NODE_TYPE_MAIN_SEQ},
      {"nil", ST_TLTIME_NODE_TYPE_NIL},
      {"tmRoot", ST_TLTIME_NODE_TYPE_TM_ROOT},
      {"withEffect", ST_TLTIME_NODE_TYPE_WITH_EFFECT},
      {"withGroup", ST_TLTIME_NODE_TYPE_WITH_GROUP}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLTIME_NODE_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 10, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLTIME_NODE_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tltime-node-preset-class-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tltime_node_preset_class_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tltime_node_preset_class_type_token_enum
pptx_get_st_tltime_node_preset_class_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"emph", ST_TLTIME_NODE_PRESET_CLASS_TYPE_EMPH},
      {"entr", ST_TLTIME_NODE_PRESET_CLASS_TYPE_ENTR},
      {"exit", ST_TLTIME_NODE_PRESET_CLASS_TYPE_EXIT},
      {"mediacall", ST_TLTIME_NODE_PRESET_CLASS_TYPE_MEDIACALL},
      {"nil", ST_TLTIME_NODE_PRESET_CLASS_TYPE_NIL},
      {"path", ST_TLTIME_NODE_PRESET_CLASS_TYPE_PATH},
      {"verb", ST_TLTIME_NODE_PRESET_CLASS_TYPE_VERB}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLTIME_NODE_PRESET_CLASS_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLTIME_NODE_PRESET_CLASS_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-connector-routing.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_connector_routing_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_connector_routing_token_enum
pptx_get_st_connector_routing(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"bend", ST_CONNECTOR_ROUTING_BEND},
      {"curve", ST_CONNECTOR_ROUTING_CURVE},
      {"longCurve", ST_CONNECTOR_ROUTING_LONG_CURVE},
      {"nil", ST_CONNECTOR_ROUTING_NIL},
      {"stra", ST_CONNECTOR_ROUTING_STRA}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CONNECTOR_ROUTING_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CONNECTOR_ROUTING_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

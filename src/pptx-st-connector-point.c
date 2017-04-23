#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-connector-point.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_connector_point_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_connector_point_token_enum
pptx_get_st_connector_point(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[12] = {
      {"auto", ST_CONNECTOR_POINT_AUTO},
      {"bCtr", ST_CONNECTOR_POINT_B_CTR},
      {"bL", ST_CONNECTOR_POINT_B_L},
      {"bR", ST_CONNECTOR_POINT_B_R},
      {"ctr", ST_CONNECTOR_POINT_CTR},
      {"midL", ST_CONNECTOR_POINT_MID_L},
      {"midR", ST_CONNECTOR_POINT_MID_R},
      {"nil", ST_CONNECTOR_POINT_NIL},
      {"radial", ST_CONNECTOR_POINT_RADIAL},
      {"tCtr", ST_CONNECTOR_POINT_T_CTR},
      {"tL", ST_CONNECTOR_POINT_T_L},
      {"tR", ST_CONNECTOR_POINT_T_R}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CONNECTOR_POINT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 12, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CONNECTOR_POINT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

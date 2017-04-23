#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tldiagram-build-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tldiagram_build_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tldiagram_build_type_token_enum
pptx_get_st_tldiagram_build_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[18] = {
      {"allAtOnce", ST_TLDIAGRAM_BUILD_TYPE_ALL_AT_ONCE},
      {"breadthByLvl", ST_TLDIAGRAM_BUILD_TYPE_BREADTH_BY_LVL},
      {"breadthByNode", ST_TLDIAGRAM_BUILD_TYPE_BREADTH_BY_NODE},
      {"ccw", ST_TLDIAGRAM_BUILD_TYPE_CCW},
      {"ccwIn", ST_TLDIAGRAM_BUILD_TYPE_CCW_IN},
      {"ccwOut", ST_TLDIAGRAM_BUILD_TYPE_CCW_OUT},
      {"cust", ST_TLDIAGRAM_BUILD_TYPE_CUST},
      {"cw", ST_TLDIAGRAM_BUILD_TYPE_CW},
      {"cwIn", ST_TLDIAGRAM_BUILD_TYPE_CW_IN},
      {"cwOut", ST_TLDIAGRAM_BUILD_TYPE_CW_OUT},
      {"depthByBranch", ST_TLDIAGRAM_BUILD_TYPE_DEPTH_BY_BRANCH},
      {"depthByNode", ST_TLDIAGRAM_BUILD_TYPE_DEPTH_BY_NODE},
      {"down", ST_TLDIAGRAM_BUILD_TYPE_DOWN},
      {"inByRing", ST_TLDIAGRAM_BUILD_TYPE_IN_BY_RING},
      {"nil", ST_TLDIAGRAM_BUILD_TYPE_NIL},
      {"outByRing", ST_TLDIAGRAM_BUILD_TYPE_OUT_BY_RING},
      {"up", ST_TLDIAGRAM_BUILD_TYPE_UP},
      {"whole", ST_TLDIAGRAM_BUILD_TYPE_WHOLE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLDIAGRAM_BUILD_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 18, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLDIAGRAM_BUILD_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-shape.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_shape_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_shape_text_enum
pptx_get_st_shape(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"box", ST_SHAPE_BOX},
      {"cone", ST_SHAPE_CONE},
      {"coneToMax", ST_SHAPE_CONE_TO_MAX},
      {"cylinder", ST_SHAPE_CYLINDER},
      {"nil", ST_SHAPE_NIL},
      {"pyramid", ST_SHAPE_PYRAMID},
      {"pyramidToMax", ST_SHAPE_PYRAMID_TO_MAX}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_SHAPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_SHAPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

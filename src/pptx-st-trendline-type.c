#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-trendline-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_trendline_type_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_trendline_type_text_enum
pptx_get_st_trendline_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"exp", ST_TRENDLINE_TYPE_EXP},
      {"linear", ST_TRENDLINE_TYPE_LINEAR},
      {"log", ST_TRENDLINE_TYPE_LOG},
      {"movingAvg", ST_TRENDLINE_TYPE_MOVING_AVG},
      {"nil", ST_TRENDLINE_TYPE_NIL},
      {"poly", ST_TRENDLINE_TYPE_POLY},
      {"power", ST_TRENDLINE_TYPE_POWER}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TRENDLINE_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TRENDLINE_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-bar-grouping.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_bar_grouping_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_bar_grouping_text_enum
pptx_get_st_bar_grouping(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"clustered", ST_BAR_GROUPING_CLUSTERED},
      {"nil", ST_BAR_GROUPING_NIL},
      {"percentStacked", ST_BAR_GROUPING_PERCENT_STACKED},
      {"stacked", ST_BAR_GROUPING_STACKED},
      {"standard", ST_BAR_GROUPING_STANDARD}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_BAR_GROUPING_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_BAR_GROUPING_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

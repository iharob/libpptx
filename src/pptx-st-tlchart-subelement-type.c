#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tlchart-subelement-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tlchart_subelement_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tlchart_subelement_type_token_enum
pptx_get_st_tlchart_subelement_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[6] = {
      {"category", ST_TLCHART_SUBELEMENT_TYPE_CATEGORY},
      {"gridLegend", ST_TLCHART_SUBELEMENT_TYPE_GRID_LEGEND},
      {"nil", ST_TLCHART_SUBELEMENT_TYPE_NIL},
      {"ptInCategory", ST_TLCHART_SUBELEMENT_TYPE_PT_IN_CATEGORY},
      {"ptInSeries", ST_TLCHART_SUBELEMENT_TYPE_PT_IN_SERIES},
      {"series", ST_TLCHART_SUBELEMENT_TYPE_SERIES}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLCHART_SUBELEMENT_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 6, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLCHART_SUBELEMENT_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-chart-build-step.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_chart_build_step_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_chart_build_step_token_enum
pptx_get_st_chart_build_step(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"allPts", ST_CHART_BUILD_STEP_ALL_PTS},
      {"category", ST_CHART_BUILD_STEP_CATEGORY},
      {"gridLegend", ST_CHART_BUILD_STEP_GRID_LEGEND},
      {"nil", ST_CHART_BUILD_STEP_NIL},
      {"ptInCategory", ST_CHART_BUILD_STEP_PT_IN_CATEGORY},
      {"ptInSeries", ST_CHART_BUILD_STEP_PT_IN_SERIES},
      {"series", ST_CHART_BUILD_STEP_SERIES}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CHART_BUILD_STEP_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CHART_BUILD_STEP_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

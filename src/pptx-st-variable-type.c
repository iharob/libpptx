#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-variable-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_variable_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_variable_type_token_enum
pptx_get_st_variable_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[11] = {
      {"animLvl", ST_VARIABLE_TYPE_ANIM_LVL},
      {"animOne", ST_VARIABLE_TYPE_ANIM_ONE},
      {"bulEnabled", ST_VARIABLE_TYPE_BUL_ENABLED},
      {"chMax", ST_VARIABLE_TYPE_CH_MAX},
      {"chPref", ST_VARIABLE_TYPE_CH_PREF},
      {"dir", ST_VARIABLE_TYPE_DIR},
      {"hierBranch", ST_VARIABLE_TYPE_HIER_BRANCH},
      {"nil", ST_VARIABLE_TYPE_NIL},
      {"none", ST_VARIABLE_TYPE_NONE},
      {"orgChart", ST_VARIABLE_TYPE_ORG_CHART},
      {"resizeHandles", ST_VARIABLE_TYPE_RESIZE_HANDLES}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_VARIABLE_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 11, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_VARIABLE_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

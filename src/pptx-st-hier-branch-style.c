#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-hier-branch-style.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_hier_branch_style_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_hier_branch_style_token_enum
pptx_get_st_hier_branch_style(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[6] = {
      {"hang", ST_HIER_BRANCH_STYLE_HANG},
      {"init", ST_HIER_BRANCH_STYLE_INIT},
      {"l", ST_HIER_BRANCH_STYLE_L},
      {"nil", ST_HIER_BRANCH_STYLE_NIL},
      {"r", ST_HIER_BRANCH_STYLE_R},
      {"std", ST_HIER_BRANCH_STYLE_STD}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_HIER_BRANCH_STYLE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 6, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_HIER_BRANCH_STYLE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

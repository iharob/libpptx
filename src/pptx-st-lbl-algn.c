#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-lbl-algn.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_lbl_algn_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_lbl_algn_text_enum
pptx_get_st_lbl_algn(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"ctr", ST_LBL_ALGN_CTR},
      {"l", ST_LBL_ALGN_L},
      {"nil", ST_LBL_ALGN_NIL},
      {"r", ST_LBL_ALGN_R}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_LBL_ALGN_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_LBL_ALGN_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

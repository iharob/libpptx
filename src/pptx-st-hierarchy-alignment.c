#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-hierarchy-alignment.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_hierarchy_alignment_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_hierarchy_alignment_token_enum
pptx_get_st_hierarchy_alignment(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[17] = {
      {"bCtrCh", ST_HIERARCHY_ALIGNMENT_B_CTR_CH},
      {"bCtrDes", ST_HIERARCHY_ALIGNMENT_B_CTR_DES},
      {"bL", ST_HIERARCHY_ALIGNMENT_B_L},
      {"bR", ST_HIERARCHY_ALIGNMENT_B_R},
      {"lB", ST_HIERARCHY_ALIGNMENT_L_B},
      {"lCtrCh", ST_HIERARCHY_ALIGNMENT_L_CTR_CH},
      {"lCtrDes", ST_HIERARCHY_ALIGNMENT_L_CTR_DES},
      {"lT", ST_HIERARCHY_ALIGNMENT_L_T},
      {"nil", ST_HIERARCHY_ALIGNMENT_NIL},
      {"rB", ST_HIERARCHY_ALIGNMENT_R_B},
      {"rCtrCh", ST_HIERARCHY_ALIGNMENT_R_CTR_CH},
      {"rCtrDes", ST_HIERARCHY_ALIGNMENT_R_CTR_DES},
      {"rT", ST_HIERARCHY_ALIGNMENT_R_T},
      {"tCtrCh", ST_HIERARCHY_ALIGNMENT_T_CTR_CH},
      {"tCtrDes", ST_HIERARCHY_ALIGNMENT_T_CTR_DES},
      {"tL", ST_HIERARCHY_ALIGNMENT_T_L},
      {"tR", ST_HIERARCHY_ALIGNMENT_T_R}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_HIERARCHY_ALIGNMENT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 17, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_HIERARCHY_ALIGNMENT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

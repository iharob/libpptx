#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-pt-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_pt_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_pt_type_token_enum
pptx_get_st_pt_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[7] = {
      {"asst", ST_PT_TYPE_ASST},
      {"doc", ST_PT_TYPE_DOC},
      {"nil", ST_PT_TYPE_NIL},
      {"node", ST_PT_TYPE_NODE},
      {"parTrans", ST_PT_TYPE_PAR_TRANS},
      {"pres", ST_PT_TYPE_PRES},
      {"sibTrans", ST_PT_TYPE_SIB_TRANS}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PT_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 7, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PT_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

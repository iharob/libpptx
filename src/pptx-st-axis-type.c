#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-axis-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_axis_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_axis_type_token_enum
pptx_get_st_axis_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[14] = {
      {"ancst", ST_AXIS_TYPE_ANCST},
      {"ancstOrSelf", ST_AXIS_TYPE_ANCST_OR_SELF},
      {"ch", ST_AXIS_TYPE_CH},
      {"des", ST_AXIS_TYPE_DES},
      {"desOrSelf", ST_AXIS_TYPE_DES_OR_SELF},
      {"follow", ST_AXIS_TYPE_FOLLOW},
      {"followSib", ST_AXIS_TYPE_FOLLOW_SIB},
      {"nil", ST_AXIS_TYPE_NIL},
      {"none", ST_AXIS_TYPE_NONE},
      {"par", ST_AXIS_TYPE_PAR},
      {"preced", ST_AXIS_TYPE_PRECED},
      {"precedSib", ST_AXIS_TYPE_PRECED_SIB},
      {"root", ST_AXIS_TYPE_ROOT},
      {"self", ST_AXIS_TYPE_SELF}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_AXIS_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 14, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_AXIS_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

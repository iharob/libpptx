#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-err-bar-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_err_bar_type_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_err_bar_type_text_enum
pptx_get_st_err_bar_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"both", ST_ERR_BAR_TYPE_BOTH},
      {"minus", ST_ERR_BAR_TYPE_MINUS},
      {"nil", ST_ERR_BAR_TYPE_NIL},
      {"plus", ST_ERR_BAR_TYPE_PLUS}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ERR_BAR_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ERR_BAR_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

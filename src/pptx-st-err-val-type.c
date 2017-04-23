#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-err-val-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_err_val_type_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_err_val_type_text_enum
pptx_get_st_err_val_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[6] = {
      {"cust", ST_ERR_VAL_TYPE_CUST},
      {"fixedVal", ST_ERR_VAL_TYPE_FIXED_VAL},
      {"nil", ST_ERR_VAL_TYPE_NIL},
      {"percentage", ST_ERR_VAL_TYPE_PERCENTAGE},
      {"stdDev", ST_ERR_VAL_TYPE_STD_DEV},
      {"stdErr", ST_ERR_VAL_TYPE_STD_ERR}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_ERR_VAL_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 6, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_ERR_VAL_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-text-anchoring-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_text_anchoring_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_text_anchoring_type_token_enum
pptx_get_st_text_anchoring_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[6] = {
      {"b", ST_TEXT_ANCHORING_TYPE_B},
      {"ctr", ST_TEXT_ANCHORING_TYPE_CTR},
      {"dist", ST_TEXT_ANCHORING_TYPE_DIST},
      {"just", ST_TEXT_ANCHORING_TYPE_JUST},
      {"nil", ST_TEXT_ANCHORING_TYPE_NIL},
      {"t", ST_TEXT_ANCHORING_TYPE_T}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TEXT_ANCHORING_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 6, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TEXT_ANCHORING_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-text-tab-align-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_text_tab_align_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_text_tab_align_type_token_enum
pptx_get_st_text_tab_align_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[5] = {
      {"ctr", ST_TEXT_TAB_ALIGN_TYPE_CTR},
      {"dec", ST_TEXT_TAB_ALIGN_TYPE_DEC},
      {"l", ST_TEXT_TAB_ALIGN_TYPE_L},
      {"nil", ST_TEXT_TAB_ALIGN_TYPE_NIL},
      {"r", ST_TEXT_TAB_ALIGN_TYPE_R}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TEXT_TAB_ALIGN_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 5, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TEXT_TAB_ALIGN_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-page-setup-orientation.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_page_setup_orientation_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_page_setup_orientation_text_enum
pptx_get_st_page_setup_orientation(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"default", ST_PAGE_SETUP_ORIENTATION_DEFAULT},
      {"landscape", ST_PAGE_SETUP_ORIENTATION_LANDSCAPE},
      {"nil", ST_PAGE_SETUP_ORIENTATION_NIL},
      {"portrait", ST_PAGE_SETUP_ORIENTATION_PORTRAIT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PAGE_SETUP_ORIENTATION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PAGE_SETUP_ORIENTATION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

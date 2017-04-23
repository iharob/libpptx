#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-disp-blanks-as.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_disp_blanks_as_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_disp_blanks_as_text_enum
pptx_get_st_disp_blanks_as(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"gap", ST_DISP_BLANKS_AS_GAP},
      {"nil", ST_DISP_BLANKS_AS_NIL},
      {"span", ST_DISP_BLANKS_AS_SPAN},
      {"zero", ST_DISP_BLANKS_AS_ZERO}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_DISP_BLANKS_AS_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_DISP_BLANKS_AS_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

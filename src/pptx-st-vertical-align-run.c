#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-vertical-align-run.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_vertical_align_run_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_vertical_align_run_text_enum
pptx_get_st_vertical_align_run(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"baseline", ST_VERTICAL_ALIGN_RUN_BASELINE},
      {"nil", ST_VERTICAL_ALIGN_RUN_NIL},
      {"subscript", ST_VERTICAL_ALIGN_RUN_SUBSCRIPT},
      {"superscript", ST_VERTICAL_ALIGN_RUN_SUPERSCRIPT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_VERTICAL_ALIGN_RUN_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_VERTICAL_ALIGN_RUN_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

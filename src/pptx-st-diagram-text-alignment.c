#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-diagram-text-alignment.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_diagram_text_alignment_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_diagram_text_alignment_token_enum
pptx_get_st_diagram_text_alignment(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"ctr", ST_DIAGRAM_TEXT_ALIGNMENT_CTR},
      {"l", ST_DIAGRAM_TEXT_ALIGNMENT_L},
      {"nil", ST_DIAGRAM_TEXT_ALIGNMENT_NIL},
      {"r", ST_DIAGRAM_TEXT_ALIGNMENT_R}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_DIAGRAM_TEXT_ALIGNMENT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_DIAGRAM_TEXT_ALIGNMENT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

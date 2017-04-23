#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-compound-line.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_compound_line_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_compound_line_token_enum
pptx_get_st_compound_line(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[6] = {
      {"dbl", ST_COMPOUND_LINE_DBL},
      {"nil", ST_COMPOUND_LINE_NIL},
      {"sng", ST_COMPOUND_LINE_SNG},
      {"thickThin", ST_COMPOUND_LINE_THICK_THIN},
      {"thinThick", ST_COMPOUND_LINE_THIN_THICK},
      {"tri", ST_COMPOUND_LINE_TRI}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_COMPOUND_LINE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 6, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_COMPOUND_LINE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

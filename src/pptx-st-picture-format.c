#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-picture-format.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_picture_format_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_picture_format_text_enum
pptx_get_st_picture_format(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"nil", ST_PICTURE_FORMAT_NIL},
      {"stack", ST_PICTURE_FORMAT_STACK},
      {"stackScale", ST_PICTURE_FORMAT_STACK_SCALE},
      {"stretch", ST_PICTURE_FORMAT_STRETCH}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PICTURE_FORMAT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PICTURE_FORMAT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

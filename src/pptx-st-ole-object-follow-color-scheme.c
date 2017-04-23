#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-ole-object-follow-color-scheme.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_ole_object_follow_color_scheme_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_ole_object_follow_color_scheme_token_enum
pptx_get_st_ole_object_follow_color_scheme(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"full", ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_FULL},
      {"nil", ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_NIL},
      {"none", ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_NONE},
      {"textAndBackground", ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_TEXT_AND_BACKGROUND}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_OLE_OBJECT_FOLLOW_COLOR_SCHEME_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

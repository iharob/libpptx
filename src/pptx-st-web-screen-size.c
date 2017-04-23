#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-web-screen-size.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_web_screen_size_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_web_screen_size_token_enum
pptx_get_st_web_screen_size(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[12] = {
      {"1024x768", ST_WEB_SCREEN_SIZE_1024X768},
      {"1152x882", ST_WEB_SCREEN_SIZE_1152X882},
      {"1152x900", ST_WEB_SCREEN_SIZE_1152X900},
      {"1280x1024", ST_WEB_SCREEN_SIZE_1280X1024},
      {"1600x1200", ST_WEB_SCREEN_SIZE_1600X1200},
      {"1800x1400", ST_WEB_SCREEN_SIZE_1800X1400},
      {"1920x1200", ST_WEB_SCREEN_SIZE_1920X1200},
      {"544x376", ST_WEB_SCREEN_SIZE_544X376},
      {"640x480", ST_WEB_SCREEN_SIZE_640X480},
      {"720x512", ST_WEB_SCREEN_SIZE_720X512},
      {"800x600", ST_WEB_SCREEN_SIZE_800X600},
      {"nil", ST_WEB_SCREEN_SIZE_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_WEB_SCREEN_SIZE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 12, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_WEB_SCREEN_SIZE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

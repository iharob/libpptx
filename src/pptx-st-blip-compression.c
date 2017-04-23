#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-blip-compression.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_blip_compression_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_blip_compression_token_enum
pptx_get_st_blip_compression(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[6] = {
      {"email", ST_BLIP_COMPRESSION_EMAIL},
      {"hqprint", ST_BLIP_COMPRESSION_HQPRINT},
      {"nil", ST_BLIP_COMPRESSION_NIL},
      {"none", ST_BLIP_COMPRESSION_NONE},
      {"print", ST_BLIP_COMPRESSION_PRINT},
      {"screen", ST_BLIP_COMPRESSION_SCREEN}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_BLIP_COMPRESSION_NIL;
    // Perform binary search
    found = bsearch(&key, base, 6, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_BLIP_COMPRESSION_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-crypt-prov.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_crypt_prov_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_crypt_prov_text_enum
pptx_get_st_crypt_prov(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[4] = {
      {"custom", ST_CRYPT_PROV_CUSTOM},
      {"nil", ST_CRYPT_PROV_NIL},
      {"rsaAES", ST_CRYPT_PROV_RSA_AES},
      {"rsaFull", ST_CRYPT_PROV_RSA_FULL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CRYPT_PROV_NIL;
    // Perform binary search
    found = bsearch(&key, base, 4, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CRYPT_PROV_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

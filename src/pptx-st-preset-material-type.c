#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-preset-material-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_preset_material_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_preset_material_type_token_enum
pptx_get_st_preset_material_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[16] = {
      {"clear", ST_PRESET_MATERIAL_TYPE_CLEAR},
      {"dkEdge", ST_PRESET_MATERIAL_TYPE_DK_EDGE},
      {"flat", ST_PRESET_MATERIAL_TYPE_FLAT},
      {"legacyMatte", ST_PRESET_MATERIAL_TYPE_LEGACY_MATTE},
      {"legacyMetal", ST_PRESET_MATERIAL_TYPE_LEGACY_METAL},
      {"legacyPlastic", ST_PRESET_MATERIAL_TYPE_LEGACY_PLASTIC},
      {"legacyWireframe", ST_PRESET_MATERIAL_TYPE_LEGACY_WIREFRAME},
      {"matte", ST_PRESET_MATERIAL_TYPE_MATTE},
      {"metal", ST_PRESET_MATERIAL_TYPE_METAL},
      {"nil", ST_PRESET_MATERIAL_TYPE_NIL},
      {"plastic", ST_PRESET_MATERIAL_TYPE_PLASTIC},
      {"powder", ST_PRESET_MATERIAL_TYPE_POWDER},
      {"softEdge", ST_PRESET_MATERIAL_TYPE_SOFT_EDGE},
      {"softmetal", ST_PRESET_MATERIAL_TYPE_SOFTMETAL},
      {"translucentPowder", ST_PRESET_MATERIAL_TYPE_TRANSLUCENT_POWDER},
      {"warmMatte", ST_PRESET_MATERIAL_TYPE_WARM_MATTE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PRESET_MATERIAL_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 16, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PRESET_MATERIAL_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

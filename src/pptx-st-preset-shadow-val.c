#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-preset-shadow-val.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_preset_shadow_val_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_preset_shadow_val_token_enum
pptx_get_st_preset_shadow_val(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[21] = {
      {"nil", ST_PRESET_SHADOW_VAL_NIL},
      {"shdw1", ST_PRESET_SHADOW_VAL_SHDW1},
      {"shdw10", ST_PRESET_SHADOW_VAL_SHDW10},
      {"shdw11", ST_PRESET_SHADOW_VAL_SHDW11},
      {"shdw12", ST_PRESET_SHADOW_VAL_SHDW12},
      {"shdw13", ST_PRESET_SHADOW_VAL_SHDW13},
      {"shdw14", ST_PRESET_SHADOW_VAL_SHDW14},
      {"shdw15", ST_PRESET_SHADOW_VAL_SHDW15},
      {"shdw16", ST_PRESET_SHADOW_VAL_SHDW16},
      {"shdw17", ST_PRESET_SHADOW_VAL_SHDW17},
      {"shdw18", ST_PRESET_SHADOW_VAL_SHDW18},
      {"shdw19", ST_PRESET_SHADOW_VAL_SHDW19},
      {"shdw2", ST_PRESET_SHADOW_VAL_SHDW2},
      {"shdw20", ST_PRESET_SHADOW_VAL_SHDW20},
      {"shdw3", ST_PRESET_SHADOW_VAL_SHDW3},
      {"shdw4", ST_PRESET_SHADOW_VAL_SHDW4},
      {"shdw5", ST_PRESET_SHADOW_VAL_SHDW5},
      {"shdw6", ST_PRESET_SHADOW_VAL_SHDW6},
      {"shdw7", ST_PRESET_SHADOW_VAL_SHDW7},
      {"shdw8", ST_PRESET_SHADOW_VAL_SHDW8},
      {"shdw9", ST_PRESET_SHADOW_VAL_SHDW9}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PRESET_SHADOW_VAL_NIL;
    // Perform binary search
    found = bsearch(&key, base, 21, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PRESET_SHADOW_VAL_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

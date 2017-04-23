#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tlanimate-motion-path-edit-mode.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tlanimate_motion_path_edit_mode_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tlanimate_motion_path_edit_mode_token_enum
pptx_get_st_tlanimate_motion_path_edit_mode(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[3] = {
      {"fixed", ST_TLANIMATE_MOTION_PATH_EDIT_MODE_FIXED},
      {"nil", ST_TLANIMATE_MOTION_PATH_EDIT_MODE_NIL},
      {"relative", ST_TLANIMATE_MOTION_PATH_EDIT_MODE_RELATIVE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLANIMATE_MOTION_PATH_EDIT_MODE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 3, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLANIMATE_MOTION_PATH_EDIT_MODE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

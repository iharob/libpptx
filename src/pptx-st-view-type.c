#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-view-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_view_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_view_type_token_enum
pptx_get_st_view_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[9] = {
      {"handoutView", ST_VIEW_TYPE_HANDOUT_VIEW},
      {"nil", ST_VIEW_TYPE_NIL},
      {"notesMasterView", ST_VIEW_TYPE_NOTES_MASTER_VIEW},
      {"notesView", ST_VIEW_TYPE_NOTES_VIEW},
      {"outlineView", ST_VIEW_TYPE_OUTLINE_VIEW},
      {"sldMasterView", ST_VIEW_TYPE_SLD_MASTER_VIEW},
      {"sldSorterView", ST_VIEW_TYPE_SLD_SORTER_VIEW},
      {"sldThumbnailView", ST_VIEW_TYPE_SLD_THUMBNAIL_VIEW},
      {"sldView", ST_VIEW_TYPE_SLD_VIEW}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_VIEW_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 9, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_VIEW_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-photo-album-layout.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_photo_album_layout_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_photo_album_layout_token_enum
pptx_get_st_photo_album_layout(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[8] = {
      {"1pic", ST_PHOTO_ALBUM_LAYOUT_1PIC},
      {"1picTitle", ST_PHOTO_ALBUM_LAYOUT_1PIC_TITLE},
      {"2pic", ST_PHOTO_ALBUM_LAYOUT_2PIC},
      {"2picTitle", ST_PHOTO_ALBUM_LAYOUT_2PIC_TITLE},
      {"4pic", ST_PHOTO_ALBUM_LAYOUT_4PIC},
      {"4picTitle", ST_PHOTO_ALBUM_LAYOUT_4PIC_TITLE},
      {"fitToSlide", ST_PHOTO_ALBUM_LAYOUT_FIT_TO_SLIDE},
      {"nil", ST_PHOTO_ALBUM_LAYOUT_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PHOTO_ALBUM_LAYOUT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 8, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PHOTO_ALBUM_LAYOUT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

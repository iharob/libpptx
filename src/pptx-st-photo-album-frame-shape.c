#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-photo-album-frame-shape.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_photo_album_frame_shape_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_photo_album_frame_shape_token_enum
pptx_get_st_photo_album_frame_shape(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[8] = {
      {"frameStyle1", ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE1},
      {"frameStyle2", ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE2},
      {"frameStyle3", ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE3},
      {"frameStyle4", ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE4},
      {"frameStyle5", ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE5},
      {"frameStyle6", ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE6},
      {"frameStyle7", ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE7},
      {"nil", ST_PHOTO_ALBUM_FRAME_SHAPE_NIL}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PHOTO_ALBUM_FRAME_SHAPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 8, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PHOTO_ALBUM_FRAME_SHAPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}

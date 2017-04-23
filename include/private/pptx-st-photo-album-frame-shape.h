#ifndef __PPTX_ST_PHOTO_ALBUM_FRAME_SHAPE_H__
#define __PPTX_ST_PHOTO_ALBUM_FRAME_SHAPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_photo_album_frame_shape_token_enum {
    ST_PHOTO_ALBUM_FRAME_SHAPE_NIL,
    ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE5,
    ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE4,
    ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE7,
    ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE6,
    ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE1,
    ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE3,
    ST_PHOTO_ALBUM_FRAME_SHAPE_FRAME_STYLE2
} pptx_st_photo_album_frame_shape_token_enum;

pptx_st_photo_album_frame_shape_token_enum pptx_get_st_photo_album_frame_shape(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PHOTO_ALBUM_FRAME_SHAPE_H__ */

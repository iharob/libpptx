#ifndef __PPTX_ST_PHOTO_ALBUM_LAYOUT_H__
#define __PPTX_ST_PHOTO_ALBUM_LAYOUT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_photo_album_layout_token_enum {
    ST_PHOTO_ALBUM_LAYOUT_4PIC,
    ST_PHOTO_ALBUM_LAYOUT_NIL,
    ST_PHOTO_ALBUM_LAYOUT_1PIC,
    ST_PHOTO_ALBUM_LAYOUT_FIT_TO_SLIDE,
    ST_PHOTO_ALBUM_LAYOUT_2PIC,
    ST_PHOTO_ALBUM_LAYOUT_4PIC_TITLE,
    ST_PHOTO_ALBUM_LAYOUT_2PIC_TITLE,
    ST_PHOTO_ALBUM_LAYOUT_1PIC_TITLE
} pptx_st_photo_album_layout_token_enum;

pptx_st_photo_album_layout_token_enum pptx_get_st_photo_album_layout(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PHOTO_ALBUM_LAYOUT_H__ */

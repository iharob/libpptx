#ifndef __PPTX_CT_P_PHOTO_ALBUM_H__
#define __PPTX_CT_P_PHOTO_ALBUM_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;
typedef enum pptx_st_photo_album_layout_token_enum pptx_st_photo_album_layout_token_enum;
typedef enum pptx_st_photo_album_frame_shape_token_enum pptx_st_photo_album_frame_shape_token_enum;

typedef struct pptx_ct_p_photo_album_s pptx_ct_p_photo_album;
pptx_ct_p_photo_album *pptx_ct_p_photo_album_new(xmlNode *node);
void pptx_ct_p_photo_album_free(pptx_ct_p_photo_album *obj);
pptx_ct_p_extension_list *pptx_ct_p_photo_album_get_ext_lst(const pptx_ct_p_photo_album *const obj);
pptx_bool pptx_ct_p_photo_album_get_bw(const pptx_ct_p_photo_album *const obj);
pptx_bool pptx_ct_p_photo_album_get_show_captions(const pptx_ct_p_photo_album *const obj);
pptx_st_photo_album_layout_token_enum pptx_ct_p_photo_album_get_layout(const pptx_ct_p_photo_album *const obj);
pptx_st_photo_album_frame_shape_token_enum pptx_ct_p_photo_album_get_frame(const pptx_ct_p_photo_album *const obj);
int32_t pptx_ct_p_photo_album_get_index(pptx_ct_p_photo_album *obj);

#endif /* __PPTX_CT_P_PHOTO_ALBUM_H__ */

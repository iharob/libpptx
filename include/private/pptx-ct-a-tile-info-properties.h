#ifndef __PPTX_CT_A_TILE_INFO_PROPERTIES_H__
#define __PPTX_CT_A_TILE_INFO_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tile_flip_mode_token_enum pptx_st_tile_flip_mode_token_enum;
typedef enum pptx_st_rect_alignment_token_enum pptx_st_rect_alignment_token_enum;

typedef struct pptx_ct_a_tile_info_properties_s pptx_ct_a_tile_info_properties;
pptx_ct_a_tile_info_properties *pptx_ct_a_tile_info_properties_new(xmlNode *node);
void pptx_ct_a_tile_info_properties_free(pptx_ct_a_tile_info_properties *obj);
pptx_string pptx_ct_a_tile_info_properties_get_tx(const pptx_ct_a_tile_info_properties *const obj);
pptx_string pptx_ct_a_tile_info_properties_get_ty(const pptx_ct_a_tile_info_properties *const obj);
pptx_string pptx_ct_a_tile_info_properties_get_sx(const pptx_ct_a_tile_info_properties *const obj);
pptx_string pptx_ct_a_tile_info_properties_get_sy(const pptx_ct_a_tile_info_properties *const obj);
pptx_st_tile_flip_mode_token_enum pptx_ct_a_tile_info_properties_get_flip(const pptx_ct_a_tile_info_properties *const obj);
pptx_st_rect_alignment_token_enum pptx_ct_a_tile_info_properties_get_algn(const pptx_ct_a_tile_info_properties *const obj);
int32_t pptx_ct_a_tile_info_properties_get_index(pptx_ct_a_tile_info_properties *obj);

#endif /* __PPTX_CT_A_TILE_INFO_PROPERTIES_H__ */

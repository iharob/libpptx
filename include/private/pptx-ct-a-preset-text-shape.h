#ifndef __PPTX_CT_A_PRESET_TEXT_SHAPE_H__
#define __PPTX_CT_A_PRESET_TEXT_SHAPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_geom_guide_list_s pptx_ct_a_geom_guide_list;
typedef enum pptx_st_text_shape_type_token_enum pptx_st_text_shape_type_token_enum;

typedef struct pptx_ct_a_preset_text_shape_s pptx_ct_a_preset_text_shape;
pptx_ct_a_preset_text_shape *pptx_ct_a_preset_text_shape_new(xmlNode *node);
void pptx_ct_a_preset_text_shape_free(pptx_ct_a_preset_text_shape *obj);
pptx_ct_a_geom_guide_list *pptx_ct_a_preset_text_shape_get_av_lst(const pptx_ct_a_preset_text_shape *const obj);
pptx_st_text_shape_type_token_enum pptx_ct_a_preset_text_shape_get_prst(const pptx_ct_a_preset_text_shape *const obj);
int32_t pptx_ct_a_preset_text_shape_get_index(pptx_ct_a_preset_text_shape *obj);

#endif /* __PPTX_CT_A_PRESET_TEXT_SHAPE_H__ */

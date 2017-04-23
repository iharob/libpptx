#ifndef __PPTX_CT_A_PATTERN_FILL_PROPERTIES_H__
#define __PPTX_CT_A_PATTERN_FILL_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_color_s pptx_ct_a_color;
typedef enum pptx_st_preset_pattern_val_token_enum pptx_st_preset_pattern_val_token_enum;

typedef struct pptx_ct_a_pattern_fill_properties_s pptx_ct_a_pattern_fill_properties;
pptx_ct_a_pattern_fill_properties *pptx_ct_a_pattern_fill_properties_new(xmlNode *node);
void pptx_ct_a_pattern_fill_properties_free(pptx_ct_a_pattern_fill_properties *obj);
pptx_ct_a_color *pptx_ct_a_pattern_fill_properties_get_fg_clr(const pptx_ct_a_pattern_fill_properties *const obj);
pptx_ct_a_color *pptx_ct_a_pattern_fill_properties_get_bg_clr(const pptx_ct_a_pattern_fill_properties *const obj);
pptx_st_preset_pattern_val_token_enum pptx_ct_a_pattern_fill_properties_get_prst(const pptx_ct_a_pattern_fill_properties *const obj);
int32_t pptx_ct_a_pattern_fill_properties_get_index(pptx_ct_a_pattern_fill_properties *obj);

#endif /* __PPTX_CT_A_PATTERN_FILL_PROPERTIES_H__ */

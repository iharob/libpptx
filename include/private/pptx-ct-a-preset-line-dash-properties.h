#ifndef __PPTX_CT_A_PRESET_LINE_DASH_PROPERTIES_H__
#define __PPTX_CT_A_PRESET_LINE_DASH_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_preset_line_dash_val_token_enum pptx_st_preset_line_dash_val_token_enum;

typedef struct pptx_ct_a_preset_line_dash_properties_s pptx_ct_a_preset_line_dash_properties;
pptx_ct_a_preset_line_dash_properties *pptx_ct_a_preset_line_dash_properties_new(xmlNode *node);
void pptx_ct_a_preset_line_dash_properties_free(pptx_ct_a_preset_line_dash_properties *obj);
pptx_st_preset_line_dash_val_token_enum pptx_ct_a_preset_line_dash_properties_get_val(const pptx_ct_a_preset_line_dash_properties *const obj);
int32_t pptx_ct_a_preset_line_dash_properties_get_index(pptx_ct_a_preset_line_dash_properties *obj);

#endif /* __PPTX_CT_A_PRESET_LINE_DASH_PROPERTIES_H__ */

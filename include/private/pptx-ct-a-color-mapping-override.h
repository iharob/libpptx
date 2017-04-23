#ifndef __PPTX_CT_A_COLOR_MAPPING_OVERRIDE_H__
#define __PPTX_CT_A_COLOR_MAPPING_OVERRIDE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_empty_element_s pptx_ct_a_empty_element;
typedef struct pptx_ct_a_color_mapping_s pptx_ct_a_color_mapping;

typedef struct pptx_ct_a_color_mapping_override_s pptx_ct_a_color_mapping_override;
pptx_ct_a_color_mapping_override *pptx_ct_a_color_mapping_override_new(xmlNode *node);
void pptx_ct_a_color_mapping_override_free(pptx_ct_a_color_mapping_override *obj);
pptx_ct_a_empty_element *pptx_ct_a_color_mapping_override_get_master_clr_mapping(const pptx_ct_a_color_mapping_override *const obj);
pptx_ct_a_color_mapping *pptx_ct_a_color_mapping_override_get_override_clr_mapping(const pptx_ct_a_color_mapping_override *const obj);
int32_t pptx_ct_a_color_mapping_override_get_index(pptx_ct_a_color_mapping_override *obj);

#endif /* __PPTX_CT_A_COLOR_MAPPING_OVERRIDE_H__ */

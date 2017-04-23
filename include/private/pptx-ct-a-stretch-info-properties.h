#ifndef __PPTX_CT_A_STRETCH_INFO_PROPERTIES_H__
#define __PPTX_CT_A_STRETCH_INFO_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_relative_rect_s pptx_ct_a_relative_rect;

typedef struct pptx_ct_a_stretch_info_properties_s pptx_ct_a_stretch_info_properties;
pptx_ct_a_stretch_info_properties *pptx_ct_a_stretch_info_properties_new(xmlNode *node);
void pptx_ct_a_stretch_info_properties_free(pptx_ct_a_stretch_info_properties *obj);
pptx_ct_a_relative_rect *pptx_ct_a_stretch_info_properties_get_fill_rect(const pptx_ct_a_stretch_info_properties *const obj);
int32_t pptx_ct_a_stretch_info_properties_get_index(pptx_ct_a_stretch_info_properties *obj);

#endif /* __PPTX_CT_A_STRETCH_INFO_PROPERTIES_H__ */

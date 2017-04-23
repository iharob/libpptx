#ifndef __PPTX_CT_P_TLBY_RGB_COLOR_TRANSFORM_H__
#define __PPTX_CT_P_TLBY_RGB_COLOR_TRANSFORM_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_tlby_rgb_color_transform_s pptx_ct_p_tlby_rgb_color_transform;
pptx_ct_p_tlby_rgb_color_transform *pptx_ct_p_tlby_rgb_color_transform_new(xmlNode *node);
void pptx_ct_p_tlby_rgb_color_transform_free(pptx_ct_p_tlby_rgb_color_transform *obj);
pptx_string pptx_ct_p_tlby_rgb_color_transform_get_r(const pptx_ct_p_tlby_rgb_color_transform *const obj);
pptx_string pptx_ct_p_tlby_rgb_color_transform_get_g(const pptx_ct_p_tlby_rgb_color_transform *const obj);
pptx_string pptx_ct_p_tlby_rgb_color_transform_get_b(const pptx_ct_p_tlby_rgb_color_transform *const obj);
int32_t pptx_ct_p_tlby_rgb_color_transform_get_index(pptx_ct_p_tlby_rgb_color_transform *obj);

#endif /* __PPTX_CT_P_TLBY_RGB_COLOR_TRANSFORM_H__ */

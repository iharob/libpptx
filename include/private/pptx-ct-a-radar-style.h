#ifndef __PPTX_CT_A_RADAR_STYLE_H__
#define __PPTX_CT_A_RADAR_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_radar_style_text_enum pptx_st_radar_style_text_enum;

typedef struct pptx_ct_a_radar_style_s pptx_ct_a_radar_style;
pptx_ct_a_radar_style *pptx_ct_a_radar_style_new(xmlNode *node);
void pptx_ct_a_radar_style_free(pptx_ct_a_radar_style *obj);
pptx_st_radar_style_text_enum pptx_ct_a_radar_style_get_val(const pptx_ct_a_radar_style *const obj);
int32_t pptx_ct_a_radar_style_get_index(pptx_ct_a_radar_style *obj);

#endif /* __PPTX_CT_A_RADAR_STYLE_H__ */

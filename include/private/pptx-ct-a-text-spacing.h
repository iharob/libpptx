#ifndef __PPTX_CT_A_TEXT_SPACING_H__
#define __PPTX_CT_A_TEXT_SPACING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_spacing_percent_s pptx_ct_a_text_spacing_percent;
typedef struct pptx_ct_a_text_spacing_point_s pptx_ct_a_text_spacing_point;

typedef struct pptx_ct_a_text_spacing_s pptx_ct_a_text_spacing;
pptx_ct_a_text_spacing *pptx_ct_a_text_spacing_new(xmlNode *node);
void pptx_ct_a_text_spacing_free(pptx_ct_a_text_spacing *obj);
pptx_ct_a_text_spacing_percent *pptx_ct_a_text_spacing_get_spc_pct(const pptx_ct_a_text_spacing *const obj);
pptx_ct_a_text_spacing_point *pptx_ct_a_text_spacing_get_spc_pts(const pptx_ct_a_text_spacing *const obj);
int32_t pptx_ct_a_text_spacing_get_index(pptx_ct_a_text_spacing *obj);

#endif /* __PPTX_CT_A_TEXT_SPACING_H__ */

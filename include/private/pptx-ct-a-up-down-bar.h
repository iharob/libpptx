#ifndef __PPTX_CT_A_UP_DOWN_BAR_H__
#define __PPTX_CT_A_UP_DOWN_BAR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;

typedef struct pptx_ct_a_up_down_bar_s pptx_ct_a_up_down_bar;
pptx_ct_a_up_down_bar *pptx_ct_a_up_down_bar_new(xmlNode *node);
void pptx_ct_a_up_down_bar_free(pptx_ct_a_up_down_bar *obj);
pptx_ct_a_shape_properties *pptx_ct_a_up_down_bar_get_sp_pr(const pptx_ct_a_up_down_bar *const obj);
int32_t pptx_ct_a_up_down_bar_get_index(pptx_ct_a_up_down_bar *obj);

#endif /* __PPTX_CT_A_UP_DOWN_BAR_H__ */

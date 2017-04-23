#ifndef __PPTX_CT_A_BUBBLE_SCALE_H__
#define __PPTX_CT_A_BUBBLE_SCALE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_bubble_scale_s pptx_ct_a_bubble_scale;
pptx_ct_a_bubble_scale *pptx_ct_a_bubble_scale_new(xmlNode *node);
void pptx_ct_a_bubble_scale_free(pptx_ct_a_bubble_scale *obj);
pptx_string pptx_ct_a_bubble_scale_get_val(const pptx_ct_a_bubble_scale *const obj);
int32_t pptx_ct_a_bubble_scale_get_index(pptx_ct_a_bubble_scale *obj);

#endif /* __PPTX_CT_A_BUBBLE_SCALE_H__ */

#ifndef __PPTX_CT_A_POSITIVE_FIXED_ANGLE_H__
#define __PPTX_CT_A_POSITIVE_FIXED_ANGLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_positive_fixed_angle_s pptx_ct_a_positive_fixed_angle;
pptx_ct_a_positive_fixed_angle *pptx_ct_a_positive_fixed_angle_new(xmlNode *node);
void pptx_ct_a_positive_fixed_angle_free(pptx_ct_a_positive_fixed_angle *obj);
pptx_int pptx_ct_a_positive_fixed_angle_get_val(const pptx_ct_a_positive_fixed_angle *const obj);
int32_t pptx_ct_a_positive_fixed_angle_get_index(pptx_ct_a_positive_fixed_angle *obj);

#endif /* __PPTX_CT_A_POSITIVE_FIXED_ANGLE_H__ */

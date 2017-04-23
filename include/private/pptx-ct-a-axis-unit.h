#ifndef __PPTX_CT_A_AXIS_UNIT_H__
#define __PPTX_CT_A_AXIS_UNIT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_axis_unit_s pptx_ct_a_axis_unit;
pptx_ct_a_axis_unit *pptx_ct_a_axis_unit_new(xmlNode *node);
void pptx_ct_a_axis_unit_free(pptx_ct_a_axis_unit *obj);
pptx_double pptx_ct_a_axis_unit_get_val(const pptx_ct_a_axis_unit *const obj);
int32_t pptx_ct_a_axis_unit_get_index(pptx_ct_a_axis_unit *obj);

#endif /* __PPTX_CT_A_AXIS_UNIT_H__ */

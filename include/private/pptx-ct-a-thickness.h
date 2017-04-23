#ifndef __PPTX_CT_A_THICKNESS_H__
#define __PPTX_CT_A_THICKNESS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_thickness_s pptx_ct_a_thickness;
pptx_ct_a_thickness *pptx_ct_a_thickness_new(xmlNode *node);
void pptx_ct_a_thickness_free(pptx_ct_a_thickness *obj);
pptx_uint pptx_ct_a_thickness_get_val(const pptx_ct_a_thickness *const obj);
int32_t pptx_ct_a_thickness_get_index(pptx_ct_a_thickness *obj);

#endif /* __PPTX_CT_A_THICKNESS_H__ */

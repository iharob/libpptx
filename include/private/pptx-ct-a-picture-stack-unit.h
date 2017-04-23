#ifndef __PPTX_CT_A_PICTURE_STACK_UNIT_H__
#define __PPTX_CT_A_PICTURE_STACK_UNIT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_picture_stack_unit_s pptx_ct_a_picture_stack_unit;
pptx_ct_a_picture_stack_unit *pptx_ct_a_picture_stack_unit_new(xmlNode *node);
void pptx_ct_a_picture_stack_unit_free(pptx_ct_a_picture_stack_unit *obj);
pptx_double pptx_ct_a_picture_stack_unit_get_val(const pptx_ct_a_picture_stack_unit *const obj);
int32_t pptx_ct_a_picture_stack_unit_get_index(pptx_ct_a_picture_stack_unit *obj);

#endif /* __PPTX_CT_A_PICTURE_STACK_UNIT_H__ */

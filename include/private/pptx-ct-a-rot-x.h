#ifndef __PPTX_CT_A_ROT_X_H__
#define __PPTX_CT_A_ROT_X_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_rot_x_s pptx_ct_a_rot_x;
pptx_ct_a_rot_x *pptx_ct_a_rot_x_new(xmlNode *node);
void pptx_ct_a_rot_x_free(pptx_ct_a_rot_x *obj);
pptx_byte pptx_ct_a_rot_x_get_val(const pptx_ct_a_rot_x *const obj);
int32_t pptx_ct_a_rot_x_get_index(pptx_ct_a_rot_x *obj);

#endif /* __PPTX_CT_A_ROT_X_H__ */

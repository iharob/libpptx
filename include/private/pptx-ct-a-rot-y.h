#ifndef __PPTX_CT_A_ROT_Y_H__
#define __PPTX_CT_A_ROT_Y_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_rot_y_s pptx_ct_a_rot_y;
pptx_ct_a_rot_y *pptx_ct_a_rot_y_new(xmlNode *node);
void pptx_ct_a_rot_y_free(pptx_ct_a_rot_y *obj);
pptx_ushort pptx_ct_a_rot_y_get_val(const pptx_ct_a_rot_y *const obj);
int32_t pptx_ct_a_rot_y_get_index(pptx_ct_a_rot_y *obj);

#endif /* __PPTX_CT_A_ROT_Y_H__ */

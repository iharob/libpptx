#ifndef __PPTX_CT_A_FIRST_SLICE_ANG_H__
#define __PPTX_CT_A_FIRST_SLICE_ANG_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_first_slice_ang_s pptx_ct_a_first_slice_ang;
pptx_ct_a_first_slice_ang *pptx_ct_a_first_slice_ang_new(xmlNode *node);
void pptx_ct_a_first_slice_ang_free(pptx_ct_a_first_slice_ang *obj);
pptx_ushort pptx_ct_a_first_slice_ang_get_val(const pptx_ct_a_first_slice_ang *const obj);
int32_t pptx_ct_a_first_slice_ang_get_index(pptx_ct_a_first_slice_ang *obj);

#endif /* __PPTX_CT_A_FIRST_SLICE_ANG_H__ */

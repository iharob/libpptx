#ifndef __PPTX_CT_A_LBL_OFFSET_H__
#define __PPTX_CT_A_LBL_OFFSET_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_lbl_offset_s pptx_ct_a_lbl_offset;
pptx_ct_a_lbl_offset *pptx_ct_a_lbl_offset_new(xmlNode *node);
void pptx_ct_a_lbl_offset_free(pptx_ct_a_lbl_offset *obj);
pptx_string pptx_ct_a_lbl_offset_get_val(const pptx_ct_a_lbl_offset *const obj);
int32_t pptx_ct_a_lbl_offset_get_index(pptx_ct_a_lbl_offset *obj);

#endif /* __PPTX_CT_A_LBL_OFFSET_H__ */

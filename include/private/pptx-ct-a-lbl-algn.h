#ifndef __PPTX_CT_A_LBL_ALGN_H__
#define __PPTX_CT_A_LBL_ALGN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_lbl_algn_text_enum pptx_st_lbl_algn_text_enum;

typedef struct pptx_ct_a_lbl_algn_s pptx_ct_a_lbl_algn;
pptx_ct_a_lbl_algn *pptx_ct_a_lbl_algn_new(xmlNode *node);
void pptx_ct_a_lbl_algn_free(pptx_ct_a_lbl_algn *obj);
pptx_st_lbl_algn_text_enum pptx_ct_a_lbl_algn_get_val(const pptx_ct_a_lbl_algn *const obj);
int32_t pptx_ct_a_lbl_algn_get_index(pptx_ct_a_lbl_algn *obj);

#endif /* __PPTX_CT_A_LBL_ALGN_H__ */

#ifndef __PPTX_CT_A_NUM_VAL_H__
#define __PPTX_CT_A_NUM_VAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_num_val_s pptx_ct_a_num_val;
pptx_ct_a_num_val *pptx_ct_a_num_val_new(xmlNode *node);
void pptx_ct_a_num_val_free(pptx_ct_a_num_val *obj);
pptx_string pptx_ct_a_num_val_get_v(const pptx_ct_a_num_val *const obj);
pptx_uint pptx_ct_a_num_val_get_idx(const pptx_ct_a_num_val *const obj);
pptx_string pptx_ct_a_num_val_get_format_code(const pptx_ct_a_num_val *const obj);
int32_t pptx_ct_a_num_val_get_index(pptx_ct_a_num_val *obj);

#endif /* __PPTX_CT_A_NUM_VAL_H__ */

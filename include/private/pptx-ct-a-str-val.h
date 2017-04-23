#ifndef __PPTX_CT_A_STR_VAL_H__
#define __PPTX_CT_A_STR_VAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_str_val_s pptx_ct_a_str_val;
pptx_ct_a_str_val *pptx_ct_a_str_val_new(xmlNode *node);
void pptx_ct_a_str_val_free(pptx_ct_a_str_val *obj);
pptx_string pptx_ct_a_str_val_get_v(const pptx_ct_a_str_val *const obj);
pptx_uint pptx_ct_a_str_val_get_idx(const pptx_ct_a_str_val *const obj);
int32_t pptx_ct_a_str_val_get_index(pptx_ct_a_str_val *obj);

#endif /* __PPTX_CT_A_STR_VAL_H__ */

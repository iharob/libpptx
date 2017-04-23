#ifndef __PPTX_CT_A_UNSIGNED_INT_H__
#define __PPTX_CT_A_UNSIGNED_INT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_unsigned_int_s pptx_ct_a_unsigned_int;
pptx_ct_a_unsigned_int *pptx_ct_a_unsigned_int_new(xmlNode *node);
void pptx_ct_a_unsigned_int_free(pptx_ct_a_unsigned_int *obj);
pptx_uint pptx_ct_a_unsigned_int_get_val(const pptx_ct_a_unsigned_int *const obj);
int32_t pptx_ct_a_unsigned_int_get_index(pptx_ct_a_unsigned_int *obj);

#endif /* __PPTX_CT_A_UNSIGNED_INT_H__ */

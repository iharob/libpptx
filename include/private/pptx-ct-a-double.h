#ifndef __PPTX_CT_A_DOUBLE_H__
#define __PPTX_CT_A_DOUBLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_double_s pptx_ct_a_double;
pptx_ct_a_double *pptx_ct_a_double_new(xmlNode *node);
void pptx_ct_a_double_free(pptx_ct_a_double *obj);
pptx_double pptx_ct_a_double_get_val(const pptx_ct_a_double *const obj);
int32_t pptx_ct_a_double_get_index(pptx_ct_a_double *obj);

#endif /* __PPTX_CT_A_DOUBLE_H__ */

#ifndef __PPTX_CT_A_BOOLEAN_H__
#define __PPTX_CT_A_BOOLEAN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_boolean_s pptx_ct_a_boolean;
pptx_ct_a_boolean *pptx_ct_a_boolean_new(xmlNode *node);
void pptx_ct_a_boolean_free(pptx_ct_a_boolean *obj);
pptx_bool pptx_ct_a_boolean_get_val(const pptx_ct_a_boolean *const obj);
int32_t pptx_ct_a_boolean_get_index(pptx_ct_a_boolean *obj);

#endif /* __PPTX_CT_A_BOOLEAN_H__ */

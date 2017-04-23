#ifndef __PPTX_CT_A_SKIP_H__
#define __PPTX_CT_A_SKIP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_skip_s pptx_ct_a_skip;
pptx_ct_a_skip *pptx_ct_a_skip_new(xmlNode *node);
void pptx_ct_a_skip_free(pptx_ct_a_skip *obj);
pptx_uint pptx_ct_a_skip_get_val(const pptx_ct_a_skip *const obj);
int32_t pptx_ct_a_skip_get_index(pptx_ct_a_skip *obj);

#endif /* __PPTX_CT_A_SKIP_H__ */

#ifndef __PPTX_CT_A_OVERLAP_H__
#define __PPTX_CT_A_OVERLAP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_overlap_s pptx_ct_a_overlap;
pptx_ct_a_overlap *pptx_ct_a_overlap_new(xmlNode *node);
void pptx_ct_a_overlap_free(pptx_ct_a_overlap *obj);
pptx_string pptx_ct_a_overlap_get_val(const pptx_ct_a_overlap *const obj);
int32_t pptx_ct_a_overlap_get_index(pptx_ct_a_overlap *obj);

#endif /* __PPTX_CT_A_OVERLAP_H__ */

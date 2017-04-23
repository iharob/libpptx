#ifndef __PPTX_CT_A_HPERCENT_H__
#define __PPTX_CT_A_HPERCENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_hpercent_s pptx_ct_a_hpercent;
pptx_ct_a_hpercent *pptx_ct_a_hpercent_new(xmlNode *node);
void pptx_ct_a_hpercent_free(pptx_ct_a_hpercent *obj);
pptx_string pptx_ct_a_hpercent_get_val(const pptx_ct_a_hpercent *const obj);
int32_t pptx_ct_a_hpercent_get_index(pptx_ct_a_hpercent *obj);

#endif /* __PPTX_CT_A_HPERCENT_H__ */

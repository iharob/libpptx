#ifndef __PPTX_CT_A_PROTECTION_H__
#define __PPTX_CT_A_PROTECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_protection_s pptx_ct_a_protection;
pptx_ct_a_protection *pptx_ct_a_protection_new(xmlNode *node);
void pptx_ct_a_protection_free(pptx_ct_a_protection *obj);
pptx_bool pptx_ct_a_protection_get_chart_object(const pptx_ct_a_protection *const obj);
pptx_bool pptx_ct_a_protection_get_data(const pptx_ct_a_protection *const obj);
pptx_bool pptx_ct_a_protection_get_formatting(const pptx_ct_a_protection *const obj);
pptx_bool pptx_ct_a_protection_get_selection(const pptx_ct_a_protection *const obj);
pptx_bool pptx_ct_a_protection_get_user_interface(const pptx_ct_a_protection *const obj);
int32_t pptx_ct_a_protection_get_index(pptx_ct_a_protection *obj);

#endif /* __PPTX_CT_A_PROTECTION_H__ */

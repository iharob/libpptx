#ifndef __PPTX_CT_A_NO_FILL_PROPERTIES_H__
#define __PPTX_CT_A_NO_FILL_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_no_fill_properties_s pptx_ct_a_no_fill_properties;
pptx_ct_a_no_fill_properties *pptx_ct_a_no_fill_properties_new(xmlNode *node);
void pptx_ct_a_no_fill_properties_free(pptx_ct_a_no_fill_properties *obj);
int32_t pptx_ct_a_no_fill_properties_get_index(pptx_ct_a_no_fill_properties *obj);

#endif /* __PPTX_CT_A_NO_FILL_PROPERTIES_H__ */

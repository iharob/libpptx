#ifndef __PPTX_CT_A_EMPTY_ELEMENT_H__
#define __PPTX_CT_A_EMPTY_ELEMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_empty_element_s pptx_ct_a_empty_element;
pptx_ct_a_empty_element *pptx_ct_a_empty_element_new(xmlNode *node);
void pptx_ct_a_empty_element_free(pptx_ct_a_empty_element *obj);
int32_t pptx_ct_a_empty_element_get_index(pptx_ct_a_empty_element *obj);

#endif /* __PPTX_CT_A_EMPTY_ELEMENT_H__ */

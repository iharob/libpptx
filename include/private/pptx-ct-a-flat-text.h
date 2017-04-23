#ifndef __PPTX_CT_A_FLAT_TEXT_H__
#define __PPTX_CT_A_FLAT_TEXT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_flat_text_s pptx_ct_a_flat_text;
pptx_ct_a_flat_text *pptx_ct_a_flat_text_new(xmlNode *node);
void pptx_ct_a_flat_text_free(pptx_ct_a_flat_text *obj);
pptx_string pptx_ct_a_flat_text_get_z(const pptx_ct_a_flat_text *const obj);
int32_t pptx_ct_a_flat_text_get_index(pptx_ct_a_flat_text *obj);

#endif /* __PPTX_CT_A_FLAT_TEXT_H__ */

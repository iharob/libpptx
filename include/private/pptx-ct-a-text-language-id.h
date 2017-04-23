#ifndef __PPTX_CT_A_TEXT_LANGUAGE_ID_H__
#define __PPTX_CT_A_TEXT_LANGUAGE_ID_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_text_language_id_s pptx_ct_a_text_language_id;
pptx_ct_a_text_language_id *pptx_ct_a_text_language_id_new(xmlNode *node);
void pptx_ct_a_text_language_id_free(pptx_ct_a_text_language_id *obj);
pptx_string pptx_ct_a_text_language_id_get_val(const pptx_ct_a_text_language_id *const obj);
int32_t pptx_ct_a_text_language_id_get_index(pptx_ct_a_text_language_id *obj);

#endif /* __PPTX_CT_A_TEXT_LANGUAGE_ID_H__ */

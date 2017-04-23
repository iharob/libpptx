#ifndef __PPTX_CT_A_REGULAR_TEXT_RUN_H__
#define __PPTX_CT_A_REGULAR_TEXT_RUN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_character_properties_s pptx_ct_a_text_character_properties;

typedef struct pptx_ct_a_regular_text_run_s pptx_ct_a_regular_text_run;
pptx_ct_a_regular_text_run *pptx_ct_a_regular_text_run_new(xmlNode *node);
void pptx_ct_a_regular_text_run_free(pptx_ct_a_regular_text_run *obj);
pptx_ct_a_text_character_properties *pptx_ct_a_regular_text_run_get_r_pr(const pptx_ct_a_regular_text_run *const obj);
pptx_string pptx_ct_a_regular_text_run_get_t(const pptx_ct_a_regular_text_run *const obj);
int32_t pptx_ct_a_regular_text_run_get_index(pptx_ct_a_regular_text_run *obj);

#endif /* __PPTX_CT_A_REGULAR_TEXT_RUN_H__ */

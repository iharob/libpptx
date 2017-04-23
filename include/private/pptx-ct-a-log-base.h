#ifndef __PPTX_CT_A_LOG_BASE_H__
#define __PPTX_CT_A_LOG_BASE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_log_base_s pptx_ct_a_log_base;
pptx_ct_a_log_base *pptx_ct_a_log_base_new(xmlNode *node);
void pptx_ct_a_log_base_free(pptx_ct_a_log_base *obj);
pptx_double pptx_ct_a_log_base_get_val(const pptx_ct_a_log_base *const obj);
int32_t pptx_ct_a_log_base_get_index(pptx_ct_a_log_base *obj);

#endif /* __PPTX_CT_A_LOG_BASE_H__ */

#ifndef __PPTX_CT_A_EXTERNAL_DATA_H__
#define __PPTX_CT_A_EXTERNAL_DATA_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_external_data_s pptx_ct_a_external_data;
pptx_ct_a_external_data *pptx_ct_a_external_data_new(xmlNode *node);
void pptx_ct_a_external_data_free(pptx_ct_a_external_data *obj);
pptx_bool pptx_ct_a_external_data_get_auto_update(const pptx_ct_a_external_data *const obj);
pptx_string pptx_ct_a_external_data_get_r_id(const pptx_ct_a_external_data *const obj);
int32_t pptx_ct_a_external_data_get_index(pptx_ct_a_external_data *obj);

#endif /* __PPTX_CT_A_EXTERNAL_DATA_H__ */

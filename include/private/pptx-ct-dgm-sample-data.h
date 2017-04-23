#ifndef __PPTX_CT_DGM_SAMPLE_DATA_H__
#define __PPTX_CT_DGM_SAMPLE_DATA_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_data_model_s pptx_ct_dgm_data_model;

typedef struct pptx_ct_dgm_sample_data_s pptx_ct_dgm_sample_data;
pptx_ct_dgm_sample_data *pptx_ct_dgm_sample_data_new(xmlNode *node);
void pptx_ct_dgm_sample_data_free(pptx_ct_dgm_sample_data *obj);
pptx_ct_dgm_data_model *pptx_ct_dgm_sample_data_get_data_model(const pptx_ct_dgm_sample_data *const obj);
pptx_bool pptx_ct_dgm_sample_data_get_use_def(const pptx_ct_dgm_sample_data *const obj);
int32_t pptx_ct_dgm_sample_data_get_index(pptx_ct_dgm_sample_data *obj);

#endif /* __PPTX_CT_DGM_SAMPLE_DATA_H__ */

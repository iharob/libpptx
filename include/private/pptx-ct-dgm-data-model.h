#ifndef __PPTX_CT_DGM_DATA_MODEL_H__
#define __PPTX_CT_DGM_DATA_MODEL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_pt_list_s pptx_ct_dgm_pt_list;
typedef struct pptx_ct_dgm_cxn_list_s pptx_ct_dgm_cxn_list;
typedef struct pptx_ct_a_background_formatting_s pptx_ct_a_background_formatting;
typedef struct pptx_ct_a_whole_e2o_formatting_s pptx_ct_a_whole_e2o_formatting;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_dgm_data_model_s pptx_ct_dgm_data_model;
pptx_ct_dgm_data_model *pptx_ct_dgm_data_model_new(xmlNode *node);
void pptx_ct_dgm_data_model_free(pptx_ct_dgm_data_model *obj);
pptx_ct_dgm_pt_list *pptx_ct_dgm_data_model_get_pt_lst(const pptx_ct_dgm_data_model *const obj);
pptx_ct_dgm_cxn_list *pptx_ct_dgm_data_model_get_cxn_lst(const pptx_ct_dgm_data_model *const obj);
pptx_ct_a_background_formatting *pptx_ct_dgm_data_model_get_bg(const pptx_ct_dgm_data_model *const obj);
pptx_ct_a_whole_e2o_formatting *pptx_ct_dgm_data_model_get_whole(const pptx_ct_dgm_data_model *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_data_model_get_ext_lst(const pptx_ct_dgm_data_model *const obj);
int32_t pptx_ct_dgm_data_model_get_index(pptx_ct_dgm_data_model *obj);

#endif /* __PPTX_CT_DGM_DATA_MODEL_H__ */

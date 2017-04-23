#ifndef __PPTX_CT_DSP_DATA_MODEL_EXT_BLOCK_H__
#define __PPTX_CT_DSP_DATA_MODEL_EXT_BLOCK_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_dsp_data_model_ext_block_s pptx_ct_dsp_data_model_ext_block;
pptx_ct_dsp_data_model_ext_block *pptx_ct_dsp_data_model_ext_block_new(xmlNode *node);
void pptx_ct_dsp_data_model_ext_block_free(pptx_ct_dsp_data_model_ext_block *obj);
pptx_string pptx_ct_dsp_data_model_ext_block_get_rel_id(const pptx_ct_dsp_data_model_ext_block *const obj);
pptx_string pptx_ct_dsp_data_model_ext_block_get_min_ver(const pptx_ct_dsp_data_model_ext_block *const obj);
int32_t pptx_ct_dsp_data_model_ext_block_get_index(pptx_ct_dsp_data_model_ext_block *obj);

#endif /* __PPTX_CT_DSP_DATA_MODEL_EXT_BLOCK_H__ */

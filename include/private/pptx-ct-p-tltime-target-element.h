#ifndef __PPTX_CT_P_TLTIME_TARGET_ELEMENT_H__
#define __PPTX_CT_P_TLTIME_TARGET_ELEMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_empty_s pptx_ct_p_empty;
typedef struct pptx_ct_a_embedded_wavaudio_file_s pptx_ct_a_embedded_wavaudio_file;
typedef struct pptx_ct_p_tlshape_target_element_s pptx_ct_p_tlshape_target_element;
typedef struct pptx_ct_p_tlsub_shape_id_s pptx_ct_p_tlsub_shape_id;

typedef struct pptx_ct_p_tltime_target_element_s pptx_ct_p_tltime_target_element;
pptx_ct_p_tltime_target_element *pptx_ct_p_tltime_target_element_new(xmlNode *node);
void pptx_ct_p_tltime_target_element_free(pptx_ct_p_tltime_target_element *obj);
pptx_ct_p_empty *pptx_ct_p_tltime_target_element_get_sld_tgt(const pptx_ct_p_tltime_target_element *const obj);
pptx_ct_a_embedded_wavaudio_file *pptx_ct_p_tltime_target_element_get_snd_tgt(const pptx_ct_p_tltime_target_element *const obj);
pptx_ct_p_tlshape_target_element *pptx_ct_p_tltime_target_element_get_sp_tgt(const pptx_ct_p_tltime_target_element *const obj);
pptx_ct_p_tlsub_shape_id *pptx_ct_p_tltime_target_element_get_ink_tgt(const pptx_ct_p_tltime_target_element *const obj);
int32_t pptx_ct_p_tltime_target_element_get_index(pptx_ct_p_tltime_target_element *obj);

#endif /* __PPTX_CT_P_TLTIME_TARGET_ELEMENT_H__ */

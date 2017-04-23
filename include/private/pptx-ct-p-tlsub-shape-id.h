#ifndef __PPTX_CT_P_TLSUB_SHAPE_ID_H__
#define __PPTX_CT_P_TLSUB_SHAPE_ID_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_tlsub_shape_id_s pptx_ct_p_tlsub_shape_id;
pptx_ct_p_tlsub_shape_id *pptx_ct_p_tlsub_shape_id_new(xmlNode *node);
void pptx_ct_p_tlsub_shape_id_free(pptx_ct_p_tlsub_shape_id *obj);
pptx_string pptx_ct_p_tlsub_shape_id_get_spid(const pptx_ct_p_tlsub_shape_id *const obj);
int32_t pptx_ct_p_tlsub_shape_id_get_index(pptx_ct_p_tlsub_shape_id *obj);

#endif /* __PPTX_CT_P_TLSUB_SHAPE_ID_H__ */

#ifndef __PPTX_CT_P_TLPOINT_H__
#define __PPTX_CT_P_TLPOINT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_tlpoint_s pptx_ct_p_tlpoint;
pptx_ct_p_tlpoint *pptx_ct_p_tlpoint_new(xmlNode *node);
void pptx_ct_p_tlpoint_free(pptx_ct_p_tlpoint *obj);
pptx_string pptx_ct_p_tlpoint_get_x(const pptx_ct_p_tlpoint *const obj);
pptx_string pptx_ct_p_tlpoint_get_y(const pptx_ct_p_tlpoint *const obj);
int32_t pptx_ct_p_tlpoint_get_index(pptx_ct_p_tlpoint *obj);

#endif /* __PPTX_CT_P_TLPOINT_H__ */

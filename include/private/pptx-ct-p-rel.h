#ifndef __PPTX_CT_P_REL_H__
#define __PPTX_CT_P_REL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_rel_s pptx_ct_p_rel;
pptx_ct_p_rel *pptx_ct_p_rel_new(xmlNode *node);
void pptx_ct_p_rel_free(pptx_ct_p_rel *obj);
pptx_string pptx_ct_p_rel_get_r_id(const pptx_ct_p_rel *const obj);
int32_t pptx_ct_p_rel_get_index(pptx_ct_p_rel *obj);

#endif /* __PPTX_CT_P_REL_H__ */

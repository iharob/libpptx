#ifndef __PPTX_CT_P_NORMAL_VIEW_PORTION_H__
#define __PPTX_CT_P_NORMAL_VIEW_PORTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_normal_view_portion_s pptx_ct_p_normal_view_portion;
pptx_ct_p_normal_view_portion *pptx_ct_p_normal_view_portion_new(xmlNode *node);
void pptx_ct_p_normal_view_portion_free(pptx_ct_p_normal_view_portion *obj);
pptx_string pptx_ct_p_normal_view_portion_get_sz(const pptx_ct_p_normal_view_portion *const obj);
pptx_bool pptx_ct_p_normal_view_portion_get_auto_adjust(const pptx_ct_p_normal_view_portion *const obj);
int32_t pptx_ct_p_normal_view_portion_get_index(pptx_ct_p_normal_view_portion *obj);

#endif /* __PPTX_CT_P_NORMAL_VIEW_PORTION_H__ */

#ifndef __PPTX_CT_P_SHOW_INFO_BROWSE_H__
#define __PPTX_CT_P_SHOW_INFO_BROWSE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_show_info_browse_s pptx_ct_p_show_info_browse;
pptx_ct_p_show_info_browse *pptx_ct_p_show_info_browse_new(xmlNode *node);
void pptx_ct_p_show_info_browse_free(pptx_ct_p_show_info_browse *obj);
pptx_bool pptx_ct_p_show_info_browse_get_show_scrollbar(const pptx_ct_p_show_info_browse *const obj);
int32_t pptx_ct_p_show_info_browse_get_index(pptx_ct_p_show_info_browse *obj);

#endif /* __PPTX_CT_P_SHOW_INFO_BROWSE_H__ */

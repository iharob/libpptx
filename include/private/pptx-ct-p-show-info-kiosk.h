#ifndef __PPTX_CT_P_SHOW_INFO_KIOSK_H__
#define __PPTX_CT_P_SHOW_INFO_KIOSK_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_show_info_kiosk_s pptx_ct_p_show_info_kiosk;
pptx_ct_p_show_info_kiosk *pptx_ct_p_show_info_kiosk_new(xmlNode *node);
void pptx_ct_p_show_info_kiosk_free(pptx_ct_p_show_info_kiosk *obj);
pptx_uint pptx_ct_p_show_info_kiosk_get_restart(const pptx_ct_p_show_info_kiosk *const obj);
int32_t pptx_ct_p_show_info_kiosk_get_index(pptx_ct_p_show_info_kiosk *obj);

#endif /* __PPTX_CT_P_SHOW_INFO_KIOSK_H__ */

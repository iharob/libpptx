#ifndef __PPTX_CT_P_SLIDE_SYNC_PROPERTIES_H__
#define __PPTX_CT_P_SLIDE_SYNC_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;

typedef struct pptx_ct_p_slide_sync_properties_s pptx_ct_p_slide_sync_properties;
pptx_ct_p_slide_sync_properties *pptx_ct_p_slide_sync_properties_new(xmlNode *node);
void pptx_ct_p_slide_sync_properties_free(pptx_ct_p_slide_sync_properties *obj);
pptx_ct_p_extension_list *pptx_ct_p_slide_sync_properties_get_ext_lst(const pptx_ct_p_slide_sync_properties *const obj);
pptx_string pptx_ct_p_slide_sync_properties_get_server_sld_id(const pptx_ct_p_slide_sync_properties *const obj);
pptx_string pptx_ct_p_slide_sync_properties_get_server_sld_modified_time(const pptx_ct_p_slide_sync_properties *const obj);
pptx_string pptx_ct_p_slide_sync_properties_get_client_inserted_time(const pptx_ct_p_slide_sync_properties *const obj);
int32_t pptx_ct_p_slide_sync_properties_get_index(pptx_ct_p_slide_sync_properties *obj);

#endif /* __PPTX_CT_P_SLIDE_SYNC_PROPERTIES_H__ */

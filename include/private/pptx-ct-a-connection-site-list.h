#ifndef __PPTX_CT_A_CONNECTION_SITE_LIST_H__
#define __PPTX_CT_A_CONNECTION_SITE_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_connection_site_s pptx_ct_a_connection_site;

typedef struct pptx_ct_a_connection_site_list_s pptx_ct_a_connection_site_list;
pptx_ct_a_connection_site_list *pptx_ct_a_connection_site_list_new(xmlNode *node);
void pptx_ct_a_connection_site_list_free(pptx_ct_a_connection_site_list *obj);
pptx_ct_a_connection_site **pptx_ct_a_connection_site_list_get_cxn(const pptx_ct_a_connection_site_list *const obj);
int32_t pptx_ct_a_connection_site_list_get_index(pptx_ct_a_connection_site_list *obj);

#endif /* __PPTX_CT_A_CONNECTION_SITE_LIST_H__ */

#ifndef __PPTX_CT_A_CONNECTION_SITE_H__
#define __PPTX_CT_A_CONNECTION_SITE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_adj_point_2d_s pptx_ct_a_adj_point_2d;

typedef struct pptx_ct_a_connection_site_s pptx_ct_a_connection_site;
pptx_ct_a_connection_site *pptx_ct_a_connection_site_new(xmlNode *node);
void pptx_ct_a_connection_site_free(pptx_ct_a_connection_site *obj);
pptx_ct_a_adj_point_2d *pptx_ct_a_connection_site_get_pos(const pptx_ct_a_connection_site *const obj);
pptx_string pptx_ct_a_connection_site_get_ang(const pptx_ct_a_connection_site *const obj);
int32_t pptx_ct_a_connection_site_get_index(pptx_ct_a_connection_site *obj);

#endif /* __PPTX_CT_A_CONNECTION_SITE_H__ */

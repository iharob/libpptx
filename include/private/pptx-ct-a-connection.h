#ifndef __PPTX_CT_A_CONNECTION_H__
#define __PPTX_CT_A_CONNECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_connection_s pptx_ct_a_connection;
pptx_ct_a_connection *pptx_ct_a_connection_new(xmlNode *node);
void pptx_ct_a_connection_free(pptx_ct_a_connection *obj);
pptx_uint pptx_ct_a_connection_get_id(const pptx_ct_a_connection *const obj);
pptx_uint pptx_ct_a_connection_get_idx(const pptx_ct_a_connection *const obj);
int32_t pptx_ct_a_connection_get_index(pptx_ct_a_connection *obj);

#endif /* __PPTX_CT_A_CONNECTION_H__ */

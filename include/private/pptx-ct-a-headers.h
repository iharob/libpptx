#ifndef __PPTX_CT_A_HEADERS_H__
#define __PPTX_CT_A_HEADERS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_headers_s pptx_ct_a_headers;
pptx_ct_a_headers *pptx_ct_a_headers_new(xmlNode *node);
void pptx_ct_a_headers_free(pptx_ct_a_headers *obj);
pptx_string pptx_ct_a_headers_get_header(const pptx_ct_a_headers *const obj);
int32_t pptx_ct_a_headers_get_index(pptx_ct_a_headers *obj);

#endif /* __PPTX_CT_A_HEADERS_H__ */

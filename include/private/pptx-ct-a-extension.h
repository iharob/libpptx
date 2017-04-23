#ifndef __PPTX_CT_A_EXTENSION_H__
#define __PPTX_CT_A_EXTENSION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_any_s pptx_any;

typedef struct pptx_ct_a_extension_s pptx_ct_a_extension;
pptx_ct_a_extension *pptx_ct_a_extension_new(xmlNode *node);
void pptx_ct_a_extension_free(pptx_ct_a_extension *obj);
pptx_any *pptx_ct_a_extension_get_items(const pptx_ct_a_extension *const obj);
pptx_string pptx_ct_a_extension_get_uri(const pptx_ct_a_extension *const obj);
int32_t pptx_ct_a_extension_get_index(pptx_ct_a_extension *obj);

#endif /* __PPTX_CT_A_EXTENSION_H__ */

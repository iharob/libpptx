#ifndef __PPTX_CT_A_PIVOT_SOURCE_H__
#define __PPTX_CT_A_PIVOT_SOURCE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_pivot_source_s pptx_ct_a_pivot_source;
pptx_ct_a_pivot_source *pptx_ct_a_pivot_source_new(xmlNode *node);
void pptx_ct_a_pivot_source_free(pptx_ct_a_pivot_source *obj);
pptx_string pptx_ct_a_pivot_source_get_name(const pptx_ct_a_pivot_source *const obj);
pptx_uint pptx_ct_a_pivot_source_get_fmt_id(const pptx_ct_a_pivot_source *const obj);
pptx_ct_a_extension_list **pptx_ct_a_pivot_source_get_ext_lst(const pptx_ct_a_pivot_source *const obj);
int32_t pptx_ct_a_pivot_source_get_index(pptx_ct_a_pivot_source *obj);

#endif /* __PPTX_CT_A_PIVOT_SOURCE_H__ */

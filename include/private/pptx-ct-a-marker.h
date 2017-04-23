#ifndef __PPTX_CT_A_MARKER_H__
#define __PPTX_CT_A_MARKER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_marker_style_s pptx_ct_a_marker_style;
typedef struct pptx_ct_a_marker_size_s pptx_ct_a_marker_size;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_marker_s pptx_ct_a_marker;
pptx_ct_a_marker *pptx_ct_a_marker_new(xmlNode *node);
void pptx_ct_a_marker_free(pptx_ct_a_marker *obj);
pptx_ct_a_marker_style *pptx_ct_a_marker_get_symbol(const pptx_ct_a_marker *const obj);
pptx_ct_a_marker_size *pptx_ct_a_marker_get_size(const pptx_ct_a_marker *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_marker_get_sp_pr(const pptx_ct_a_marker *const obj);
pptx_ct_a_extension_list *pptx_ct_a_marker_get_ext_lst(const pptx_ct_a_marker *const obj);
int32_t pptx_ct_a_marker_get_index(pptx_ct_a_marker *obj);

#endif /* __PPTX_CT_A_MARKER_H__ */

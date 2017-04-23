#ifndef __PPTX_CT_A_DTABLE_H__
#define __PPTX_CT_A_DTABLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_text_body_s pptx_ct_a_text_body;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_dtable_s pptx_ct_a_dtable;
pptx_ct_a_dtable *pptx_ct_a_dtable_new(xmlNode *node);
void pptx_ct_a_dtable_free(pptx_ct_a_dtable *obj);
pptx_bool pptx_ct_a_dtable_get_show_horz_border(const pptx_ct_a_dtable *const obj);
pptx_bool pptx_ct_a_dtable_get_show_vert_border(const pptx_ct_a_dtable *const obj);
pptx_bool pptx_ct_a_dtable_get_show_outline(const pptx_ct_a_dtable *const obj);
pptx_bool pptx_ct_a_dtable_get_show_keys(const pptx_ct_a_dtable *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_dtable_get_sp_pr(const pptx_ct_a_dtable *const obj);
pptx_ct_a_text_body *pptx_ct_a_dtable_get_tx_pr(const pptx_ct_a_dtable *const obj);
pptx_ct_a_extension_list *pptx_ct_a_dtable_get_ext_lst(const pptx_ct_a_dtable *const obj);
int32_t pptx_ct_a_dtable_get_index(pptx_ct_a_dtable *obj);

#endif /* __PPTX_CT_A_DTABLE_H__ */

#ifndef __PPTX_CT_A_HYPERLINK_H__
#define __PPTX_CT_A_HYPERLINK_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_embedded_wavaudio_file_s pptx_ct_a_embedded_wavaudio_file;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_hyperlink_s pptx_ct_a_hyperlink;
pptx_ct_a_hyperlink *pptx_ct_a_hyperlink_new(xmlNode *node);
void pptx_ct_a_hyperlink_free(pptx_ct_a_hyperlink *obj);
pptx_ct_a_embedded_wavaudio_file *pptx_ct_a_hyperlink_get_snd(const pptx_ct_a_hyperlink *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_hyperlink_get_ext_lst(const pptx_ct_a_hyperlink *const obj);
pptx_string pptx_ct_a_hyperlink_get_r_id(const pptx_ct_a_hyperlink *const obj);
pptx_string pptx_ct_a_hyperlink_get_invalid_url(const pptx_ct_a_hyperlink *const obj);
pptx_string pptx_ct_a_hyperlink_get_action(const pptx_ct_a_hyperlink *const obj);
pptx_string pptx_ct_a_hyperlink_get_tgt_frame(const pptx_ct_a_hyperlink *const obj);
pptx_string pptx_ct_a_hyperlink_get_tooltip(const pptx_ct_a_hyperlink *const obj);
pptx_bool pptx_ct_a_hyperlink_get_history(const pptx_ct_a_hyperlink *const obj);
pptx_bool pptx_ct_a_hyperlink_get_highlight_click(const pptx_ct_a_hyperlink *const obj);
pptx_bool pptx_ct_a_hyperlink_get_end_snd(const pptx_ct_a_hyperlink *const obj);
int32_t pptx_ct_a_hyperlink_get_index(pptx_ct_a_hyperlink *obj);

#endif /* __PPTX_CT_A_HYPERLINK_H__ */

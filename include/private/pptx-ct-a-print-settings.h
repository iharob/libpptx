#ifndef __PPTX_CT_A_PRINT_SETTINGS_H__
#define __PPTX_CT_A_PRINT_SETTINGS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_header_footer_s pptx_ct_a_header_footer;
typedef struct pptx_ct_a_page_margins_s pptx_ct_a_page_margins;
typedef struct pptx_ct_a_page_setup_s pptx_ct_a_page_setup;
typedef struct pptx_ct_a_rel_id_s pptx_ct_a_rel_id;

typedef struct pptx_ct_a_print_settings_s pptx_ct_a_print_settings;
pptx_ct_a_print_settings *pptx_ct_a_print_settings_new(xmlNode *node);
void pptx_ct_a_print_settings_free(pptx_ct_a_print_settings *obj);
pptx_ct_a_header_footer *pptx_ct_a_print_settings_get_header_footer(const pptx_ct_a_print_settings *const obj);
pptx_ct_a_page_margins *pptx_ct_a_print_settings_get_page_margins(const pptx_ct_a_print_settings *const obj);
pptx_ct_a_page_setup *pptx_ct_a_print_settings_get_page_setup(const pptx_ct_a_print_settings *const obj);
pptx_ct_a_rel_id *pptx_ct_a_print_settings_get_legacy_drawing_hf(const pptx_ct_a_print_settings *const obj);
int32_t pptx_ct_a_print_settings_get_index(pptx_ct_a_print_settings *obj);

#endif /* __PPTX_CT_A_PRINT_SETTINGS_H__ */

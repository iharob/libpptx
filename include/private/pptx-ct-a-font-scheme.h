#ifndef __PPTX_CT_A_FONT_SCHEME_H__
#define __PPTX_CT_A_FONT_SCHEME_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_font_collection_s pptx_ct_a_font_collection;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_font_scheme_s pptx_ct_a_font_scheme;
pptx_ct_a_font_scheme *pptx_ct_a_font_scheme_new(xmlNode *node);
void pptx_ct_a_font_scheme_free(pptx_ct_a_font_scheme *obj);
pptx_ct_a_font_collection *pptx_ct_a_font_scheme_get_major_font(const pptx_ct_a_font_scheme *const obj);
pptx_ct_a_font_collection *pptx_ct_a_font_scheme_get_minor_font(const pptx_ct_a_font_scheme *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_font_scheme_get_ext_lst(const pptx_ct_a_font_scheme *const obj);
pptx_string pptx_ct_a_font_scheme_get_name(const pptx_ct_a_font_scheme *const obj);
int32_t pptx_ct_a_font_scheme_get_index(pptx_ct_a_font_scheme *obj);

#endif /* __PPTX_CT_A_FONT_SCHEME_H__ */

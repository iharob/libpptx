#ifndef __PPTX_CT_A_COLOR_SCHEME_H__
#define __PPTX_CT_A_COLOR_SCHEME_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_color_s pptx_ct_a_color;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_color_scheme_s pptx_ct_a_color_scheme;
pptx_ct_a_color_scheme *pptx_ct_a_color_scheme_new(xmlNode *node);
void pptx_ct_a_color_scheme_free(pptx_ct_a_color_scheme *obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_dk1(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_lt1(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_dk2(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_lt2(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_accent1(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_accent2(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_accent3(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_accent4(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_accent5(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_accent6(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_hlink(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_color *pptx_ct_a_color_scheme_get_fol_hlink(const pptx_ct_a_color_scheme *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_color_scheme_get_ext_lst(const pptx_ct_a_color_scheme *const obj);
pptx_string pptx_ct_a_color_scheme_get_name(const pptx_ct_a_color_scheme *const obj);
int32_t pptx_ct_a_color_scheme_get_index(pptx_ct_a_color_scheme *obj);

#endif /* __PPTX_CT_A_COLOR_SCHEME_H__ */

#ifndef __PPTX_CT_P_HEADER_FOOTER_H__
#define __PPTX_CT_P_HEADER_FOOTER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;

typedef struct pptx_ct_p_header_footer_s pptx_ct_p_header_footer;
pptx_ct_p_header_footer *pptx_ct_p_header_footer_new(xmlNode *node);
void pptx_ct_p_header_footer_free(pptx_ct_p_header_footer *obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_header_footer_get_ext_lst(const pptx_ct_p_header_footer *const obj);
pptx_bool pptx_ct_p_header_footer_get_sld_num(const pptx_ct_p_header_footer *const obj);
pptx_bool pptx_ct_p_header_footer_get_hdr(const pptx_ct_p_header_footer *const obj);
pptx_bool pptx_ct_p_header_footer_get_ftr(const pptx_ct_p_header_footer *const obj);
pptx_bool pptx_ct_p_header_footer_get_dt(const pptx_ct_p_header_footer *const obj);
int32_t pptx_ct_p_header_footer_get_index(pptx_ct_p_header_footer *obj);

#endif /* __PPTX_CT_P_HEADER_FOOTER_H__ */

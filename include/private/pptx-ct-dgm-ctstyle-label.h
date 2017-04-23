#ifndef __PPTX_CT_DGM_CTSTYLE_LABEL_H__
#define __PPTX_CT_DGM_CTSTYLE_LABEL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_colors_s pptx_ct_dgm_colors;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_dgm_ctstyle_label_s pptx_ct_dgm_ctstyle_label;
pptx_ct_dgm_ctstyle_label *pptx_ct_dgm_ctstyle_label_new(xmlNode *node);
void pptx_ct_dgm_ctstyle_label_free(pptx_ct_dgm_ctstyle_label *obj);
pptx_ct_dgm_colors *pptx_ct_dgm_ctstyle_label_get_fill_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj);
pptx_ct_dgm_colors *pptx_ct_dgm_ctstyle_label_get_lin_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj);
pptx_ct_dgm_colors *pptx_ct_dgm_ctstyle_label_get_effect_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj);
pptx_ct_dgm_colors *pptx_ct_dgm_ctstyle_label_get_tx_lin_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj);
pptx_ct_dgm_colors *pptx_ct_dgm_ctstyle_label_get_tx_fill_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj);
pptx_ct_dgm_colors *pptx_ct_dgm_ctstyle_label_get_tx_effect_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_ctstyle_label_get_ext_lst(const pptx_ct_dgm_ctstyle_label *const obj);
pptx_string pptx_ct_dgm_ctstyle_label_get_name(const pptx_ct_dgm_ctstyle_label *const obj);
int32_t pptx_ct_dgm_ctstyle_label_get_index(pptx_ct_dgm_ctstyle_label *obj);

#endif /* __PPTX_CT_DGM_CTSTYLE_LABEL_H__ */

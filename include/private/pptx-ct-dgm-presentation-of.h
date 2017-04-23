#ifndef __PPTX_CT_DGM_PRESENTATION_OF_H__
#define __PPTX_CT_DGM_PRESENTATION_OF_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_axis_type_token_enum pptx_st_axis_type_token_enum;
typedef enum pptx_st_element_type_token_enum pptx_st_element_type_token_enum;

typedef struct pptx_ct_dgm_presentation_of_s pptx_ct_dgm_presentation_of;
pptx_ct_dgm_presentation_of *pptx_ct_dgm_presentation_of_new(xmlNode *node);
void pptx_ct_dgm_presentation_of_free(pptx_ct_dgm_presentation_of *obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_presentation_of_get_ext_lst(const pptx_ct_dgm_presentation_of *const obj);
pptx_st_axis_type_token_enum pptx_ct_dgm_presentation_of_get_axis(const pptx_ct_dgm_presentation_of *const obj);
pptx_st_element_type_token_enum pptx_ct_dgm_presentation_of_get_pt_type(const pptx_ct_dgm_presentation_of *const obj);
pptx_bool pptx_ct_dgm_presentation_of_get_hide_last_trans(const pptx_ct_dgm_presentation_of *const obj);
pptx_int pptx_ct_dgm_presentation_of_get_st(const pptx_ct_dgm_presentation_of *const obj);
pptx_uint pptx_ct_dgm_presentation_of_get_cnt(const pptx_ct_dgm_presentation_of *const obj);
pptx_int pptx_ct_dgm_presentation_of_get_step(const pptx_ct_dgm_presentation_of *const obj);
int32_t pptx_ct_dgm_presentation_of_get_index(pptx_ct_dgm_presentation_of *obj);

#endif /* __PPTX_CT_DGM_PRESENTATION_OF_H__ */

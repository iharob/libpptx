#ifndef __PPTX_CT_P_BACKGROUND_H__
#define __PPTX_CT_P_BACKGROUND_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_background_properties_s pptx_ct_p_background_properties;
typedef struct pptx_ct_a_style_matrix_reference_s pptx_ct_a_style_matrix_reference;
typedef enum pptx_st_black_white_mode_token_enum pptx_st_black_white_mode_token_enum;

typedef struct pptx_ct_p_background_s pptx_ct_p_background;
pptx_ct_p_background *pptx_ct_p_background_new(xmlNode *node);
void pptx_ct_p_background_free(pptx_ct_p_background *obj);
pptx_ct_p_background_properties *pptx_ct_p_background_get_background_bg_pr(const pptx_ct_p_background *const obj);
pptx_ct_a_style_matrix_reference *pptx_ct_p_background_get_background_bg_ref(const pptx_ct_p_background *const obj);
pptx_st_black_white_mode_token_enum pptx_ct_p_background_get_bw_mode(const pptx_ct_p_background *const obj);
int32_t pptx_ct_p_background_get_index(pptx_ct_p_background *obj);

#endif /* __PPTX_CT_P_BACKGROUND_H__ */

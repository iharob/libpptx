#ifndef __PPTX_CT_P_PLACEHOLDER_H__
#define __PPTX_CT_P_PLACEHOLDER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;
typedef enum pptx_st_placeholder_type_token_enum pptx_st_placeholder_type_token_enum;
typedef enum pptx_st_direction_token_enum pptx_st_direction_token_enum;
typedef enum pptx_st_placeholder_size_token_enum pptx_st_placeholder_size_token_enum;

typedef struct pptx_ct_p_placeholder_s pptx_ct_p_placeholder;
pptx_ct_p_placeholder *pptx_ct_p_placeholder_new(xmlNode *node);
void pptx_ct_p_placeholder_free(pptx_ct_p_placeholder *obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_placeholder_get_ext_lst(const pptx_ct_p_placeholder *const obj);
pptx_st_placeholder_type_token_enum pptx_ct_p_placeholder_get_type(const pptx_ct_p_placeholder *const obj);
pptx_st_direction_token_enum pptx_ct_p_placeholder_get_orient(const pptx_ct_p_placeholder *const obj);
pptx_st_placeholder_size_token_enum pptx_ct_p_placeholder_get_sz(const pptx_ct_p_placeholder *const obj);
pptx_uint pptx_ct_p_placeholder_get_idx(const pptx_ct_p_placeholder *const obj);
pptx_bool pptx_ct_p_placeholder_get_has_custom_prompt(const pptx_ct_p_placeholder *const obj);
int32_t pptx_ct_p_placeholder_get_index(pptx_ct_p_placeholder *obj);

#endif /* __PPTX_CT_P_PLACEHOLDER_H__ */

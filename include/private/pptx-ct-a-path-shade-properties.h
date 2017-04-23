#ifndef __PPTX_CT_A_PATH_SHADE_PROPERTIES_H__
#define __PPTX_CT_A_PATH_SHADE_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_relative_rect_s pptx_ct_a_relative_rect;
typedef enum pptx_st_path_shade_type_token_enum pptx_st_path_shade_type_token_enum;

typedef struct pptx_ct_a_path_shade_properties_s pptx_ct_a_path_shade_properties;
pptx_ct_a_path_shade_properties *pptx_ct_a_path_shade_properties_new(xmlNode *node);
void pptx_ct_a_path_shade_properties_free(pptx_ct_a_path_shade_properties *obj);
pptx_ct_a_relative_rect *pptx_ct_a_path_shade_properties_get_fill_to_rect(const pptx_ct_a_path_shade_properties *const obj);
pptx_st_path_shade_type_token_enum pptx_ct_a_path_shade_properties_get_path(const pptx_ct_a_path_shade_properties *const obj);
int32_t pptx_ct_a_path_shade_properties_get_index(pptx_ct_a_path_shade_properties *obj);

#endif /* __PPTX_CT_A_PATH_SHADE_PROPERTIES_H__ */
